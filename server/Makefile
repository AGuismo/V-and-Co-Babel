NAME	     ?=	server_babel

SRCS =	      	main.cpp		\
		Application.cpp		\
		Server.cpp		\

DEPS.INC=
DEPS.LNK=

MOD.INC=
MOD.LNK=

F.C	     +=	-W -Wall -Werror
F.I	     += $(MOD.INC) $(DEPS.INC) -I./include
F.L	     += $(MOD.LNK) $(DEPS.LNK) -lboost_system -lboost_thread -lpthread
F.D	     +=

all:		start $(NAME)

$(NAME):	compile

compile_mods:
		@$(ECHO) $(ES) "Compile Modules" $(EE)

compile_deps:
		@$(ECHO) $(ES) "Compile Dependancies" $(EE)

clean_mods:
		@$(ECHO) $(ES) "Clean Modules" $(EE)

clean_deps:
		@$(ECHO) $(ES) "Clean Dependancies" $(EE)

fclean_mods:
		@$(ECHO) $(ES) "Full clean Modules" $(EE)

fclean_deps:
		@$(ECHO) $(ES) "Full clean Dependancies" $(EE)

clean:		remove_objects

fclean:		clean remove_name

re:		fclean all

include .libmake
