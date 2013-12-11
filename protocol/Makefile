## ┌───────────────────────────────────────────────────────────────────────────┐
## │                                MAKEFILE                                   │
## └───────────────────────────────────────────────────────────────────────────┘



NAME	     ?=	libprotocol.a


SRCS =	      	ARequest.cpp		\
		ServerRequest.cpp	\
		FriendRequest.cpp	\
		ChatRequest.cpp		\
		AuthRequest.cpp		\
		PersoRequest.cpp	\
		CallRequest.cpp		\
		Protocol.cpp		\
		RequestFactory.cpp	\

API.H=		./API/
SERIALIZER.DIR=	../serializer/

F.C	     +=	-W -Wall
F.I	     += -I$(API.H) -I$(SERIALIZER.DIR)/include
F.D	     +=


all:		start $(NAME)

$(NAME):	lib_compile

clean:		remove_objects

fclean:		clean remove_name

re:		fclean all























































include .libmake
