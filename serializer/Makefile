## ┌───────────────────────────────────────────────────────────────────────────┐
## │                                MAKEFILE                                   │
## └───────────────────────────────────────────────────────────────────────────┘



NAME	     ?=	libserialize.a


SRCS =		Serializer.cpp		\
		MD5.cpp			\
		Salt.cpp		\

API.H=		../protocol/API/

F.C	     +=	-W -Wall 
F.I	     += -I$(API.H)
F.D	     +=


all:		start $(NAME)

$(NAME):	lib_compile

clean:		remove_objects

fclean:		clean remove_name

re:		fclean all























































include .libmake
