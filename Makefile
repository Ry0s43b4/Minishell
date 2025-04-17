##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Compile the entire project (mandatory)
##

CC	:=	gcc

SRC=	src/main.c	\
	src/commands.c	\
	src/error_handling.c	\
	src/main_loop.c	\
	src/builtins/env.c	\
	src/builtins/cd.c	\
	src/builtins/my_setenv.c	\
	src/builtins/my_unsetenv.c	\
	src/separators/pipe.c	\
	src/separators/semicolons.c	\
	src/separators/redirections.c	\
	src/parsing.c	\

OBJ=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS	+=	-iquote./include

LDGLAGS	+=	-L./librairies -lmy

NAME=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LDGLAGS)

tests_run:
	make -C tests_unit/

clean:
	make clean -C lib/
	make clean -C tests_unit/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/
	make fclean -C tests_unit/
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
