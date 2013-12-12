NAME	     ?=	call.so

SRCS =	      	Call.cpp	\

SERVER.DIR=	../../
API.DIR=	../../../protocol/API
PROT.DIR=	../../../protocol/
SERIALIZER.DIR=	../../../serializer/
DATABASE.DIR=	../../database
INSTALL.DIR=	../lib

DEPS.INC=
DEPS.LNK=

MOD.INC=	-I$(SERVER.DIR)/include -I$(API.DIR) -I$(PROT.DIR)/include -I$(SERIALIZER.DIR)/include
MOD.INC+=	-I$(DATABASE.DIR)/include
MOD.LNK=

F.C	     +=	-W -Wall -fPIC
F.I	     += $(MOD.INC) $(DEPS.INC)
F.L	     += $(MOD.LNK) $(DEPS.LNK) -lboost_system -lboost_thread -lpthread -shared
F.D	     +=

all:		start $(NAME)

$(NAME):	compile

clean:		remove_objects

fclean:		clean remove_name

re:		fclean all

install:	$(NAME)
		cp -f $(NAME) $(INSTALL.DIR)

include .libmake
