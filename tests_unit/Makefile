##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## File used for the compilation of my unit_tests
##

CC	:=	gcc

SRC=	tests_file.c	\

CPPFLAGS	+=	iquote../include

LDGLAGS	+=	-L../librairies -lmy

tests_run:
	$(CC) -o unit_tests $(SRC) --coverage --verbose \
	-lcriterion $(LDGLAGS)
	mv unit_tests ./../

clean:
	rm -f unit_tests-*
	rm -f ./../unit_tests-*

fclean:	clean
	rm -f unit_tests
	rm -f ./../unit_tests

.PHONY:	clean fclean
