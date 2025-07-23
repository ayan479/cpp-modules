NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp 

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME) 3 5 9 7 4
	./$(NAME) `shuf -i 1-100 -n 3000 | tr "\n" " "`

.PHONY: all clean fclean re test
