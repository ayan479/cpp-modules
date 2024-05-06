#include "Phonebook.hpp"

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

    std::cout << "+--------------------------------------+\n";
    std::cout << "|Index| FirstName| LastName | NickName |\n";
    std::cout << "+--------------------------------------+\n";
    if (contacts[0].get_first_name().empty())
    {
        std::cout <<  RED << "                EMPTY" << RESET << std::endl;
    }
    for (i = 0; i < 8; i++)
    {
        if (contacts[i].get_first_name().empty())
            break;

        std::cout << "|" << std::setw(5) << i + 1 << "|";
        printwidthmanager(contacts[i].get_first_name());
        printwidthmanager(contacts[i].get_last_name());
        printwidthmanager(contacts[i].get_nickname());
        std::cout << "\n";
    }
    std::cout << "+--------------------------------------+\n";

    std::cout << "Write Index: ";
    std::cin >> input;
    if (input > 0 && input < i + 1)
    {
        std::cout << "Firstname:\t" << contacts[input - 1].get_first_name() << std::endl;
        std::cout << "Lastname:\t" << contacts[input - 1].get_last_name() << std::endl;
        std::cout << "Nickname:\t" << contacts[input - 1].get_nickname() << std::endl;
        std::cout << "Phone number:\t" << contacts[input - 1].get_phone_number() << std::endl;
        std::cout << "Darkest secret:\t" << contacts[input - 1].get_darkest_secret() << std::endl;
    }
    else
    {
        std::cout << RED << "Wrong index" << RESET <<std::endl;
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

//////////↓ Contact ↓//////////

const std::string &Contact::get_first_name()
{
	return (first_name);
}

const std::string &Contact::get_last_name()
{
	return (last_name);
}

const std::string &Contact::get_nickname()
{
	return (nickname);
}

const std::string &Contact::get_phone_number()
{
	return (phone_number);
}

const std::string &Contact::get_darkest_secret()
{
	return (darkest_secret);
}

void Contact::makecontact()
{
    std::cout << BLUE <<"Enter first name: " << std::endl;
    std::cin >> first_name;
    if (first_name.empty()) {
        std::cout << "First name cannot be empty. Try again." << std::endl;
        return;
    }

    std::cout << BLUE <<"Enter last name: " << std::endl;
    std::cin >> last_name;
    if (last_name.empty()) {
        std::cout << "Last name cannot be empty. Try again." << std::endl;
        return;
    }

    std::cout << BLUE <<"Enter nickname: " << std::endl;
    std::cin >> nickname;
    if (nickname.empty()) {
        std::cout << "Nickname cannot be empty. Try again." << std::endl;
        return;
    }

    std::cout << BLUE <<"Enter phone number: " << std::endl;
    std::cin >> phone_number;
    if (phone_number.empty()) {
        std::cout << "Phone number cannot be empty. Try again." << std::endl;
        return;
    }

    std::cout << BLUE <<"Enter darkest secret: " << std::endl;
    std::cin >> darkest_secret;
    if (darkest_secret.empty()) {
        std::cout << "Darkest secret cannot be empty. Try again." << std::endl;
        return;
    }
}