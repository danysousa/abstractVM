export	CC	=	c++
DEBUG		=	FALSE

NAME		=	avm

CFLAGS		=	-Wall -Wextra -Werror -std=c++11 -stdlib=libc++

OS			:=	$(shell uname -s)

INC			=	-I includes

INC_DIR		=	includes/

INC_FILES	=	Avm.hpp\
				Program.hpp\
				IOperand.hpp\
				Int8.hpp\
				Int16.hpp\
				Int32.hpp\
				Float.hpp\
				Double.hpp

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	srcs/

FILES		=	main.cpp\
				Avm.cpp\
				Program.cpp\
				Int8.cpp\
				Int16.cpp\
				Int32.cpp\
				Float.cpp\
				Double.cpp

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

%.o:			%.cpp $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re:				fclean all

.PHONY:			all clean fclean re