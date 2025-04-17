##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## File used for the compilation and the creation of my library
##

AR	:=	ar

SRC=	my_getnbr.c	\
	my_putchar.c	\
	my_put_nbr.c	\
	my_putstr.c	\
	my_revstr.c	\
	my_strcat.c	\
	my_strcmp.c	\
	my_strncmp.c	\
	my_strcpy.c	\
	my_strdup.c	\
	my_strlen.c	\
	my_str_to_word_array.c	\
	mini_printf/mini_printf.c	\
	mini_printf/check_flag.c

OBJ=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS	+=	-iquote../include

NAME=	libmy.a

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	mv $(NAME) ./../librairies

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../librairies/$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
