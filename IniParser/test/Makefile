NAME	     ?=	test_iniparser

SRCS =	      	main.cpp		\


F.I	     += -I./include -I../include
F.L	     += -L../ -liniparser
F.D	     +=	-W -Wall

all:		start $(NAME)

$(NAME):	compile_ini compile

compile_ini:
		@make --no-print-directory -C ../ all F.D+=$(F.D)

clean:		remove_objects
		@make --no-print-directory -C ../ clean

fclean:		clean remove_name
		@make --no-print-directory -C ../ fclean

re:		fclean all

include .libmake
