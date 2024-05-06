#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : current_contact(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::add_contact()
{
	PhoneBook::contacts[current_contact].makecontact();
	current_contact++;
	if (current_contact == 8)
		current_contact = 0;
}

void PhoneBook::printtable()
{
    int input;
    int i;

    std::cout << YELLOW << "+--------------------------------------+\n";
    std::cout << "|Index| FirstName| LastName | NickName |\n";
    std::cout << "+--------------------------------------+\n" << RESET;
    if (contacts[0].get_first_name().empty())
    {
        std::cout <<  RED << "                EMPTY" << RESET << std::endl;
    }
    for (i = 0; i < 8; i++)
    {
        if (contacts[i].get_first_name().empty())
            break;

        std::cout << YELLOW <<"|" << std::setw(5) << i + 1 << "|";
        printwidthmanager(contacts[i].get_first_name());
        printwidthmanager(contacts[i].get_last_name());
        printwidthmanager(contacts[i].get_nickname());
        std::cout << "\n";
    }
    std::cout << YELLOW << "+--------------------------------------+\n" << RESET;

    std::cout << "Write Index: ";
    std::cin >> input;
    if (input > 0 && input < i + 1)
    {
        std::cout << CYAN << BOLD <<"Firstname:\t" << contacts[input - 1].get_first_name() << std::endl;
        std::cout << "Lastname:\t" << contacts[input - 1].get_last_name() << std::endl;
        std::cout << "Nickname:\t" << contacts[input - 1].get_nickname() << std::endl;
        std::cout << "Phone number:\t" << contacts[input - 1].get_phone_number() << std::endl;
        std::cout << "Darkest secret:\t" << contacts[input - 1].get_darkest_secret() << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "Empty/Wrong index" << RESET <<std::endl;
    }
    std::cin.clear();
    std::cin.ignore(32767, '\n');
}

void PhoneBook::printwidthmanager(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".|";
	}
	else
	{
		std::cout << std::setw(10) << str << "|";
	}
}