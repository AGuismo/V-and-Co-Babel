NAME	     ?=	test_iniparser

SRCS =	      	main.cpp		\


F.C	     +=	-W -Wall
F.I	     += -I./include -I../include
F.L	     += -L../ -liniparser
F.D	     +=

all:		start $(NAME)

$(NAME):	compile

clean:		remove_objects

fclean:		clean remove_name

re:		fclean all

include .libmake
