NAME	     ?=	server_babel

SRCS =	      	main.cpp		\
		Application.cpp		\

DIR.DB=		database

DEPS.INC=
DEPS.LNK=

MOD.INC=	-I$(DIR.DB)/include
MOD.LNK=	-L$(DIR.DB) -ldb

F.C	     +=	-W -Wall -Werror
F.I	     += $(MOD.INC) $(DEPS.INC) -I./include
F.L	     += $(MOD.LNK) $(DEPS.LNK) -lboost_system -lboost_thread
F.D	     +=

all:		start $(NAME)

$(NAME):	compile compile_mods

compile_mods:
		@$(ECHO) $(ES) "Compile Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) all F.D=$(F.D)
compile_deps:
		@$(ECHO) $(ES) "Compile Dependancies" $(EE)

clean_mods:
		@$(ECHO) $(ES) "Clean Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) clean

clean_deps:
		@$(ECHO) $(ES) "Clean Dependancies" $(EE)

fclean_mods:
		@$(ECHO) $(ES) "Full clean Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) fclean

fclean_deps:
		@$(ECHO) $(ES) "Full clean Dependancies" $(EE)

clean:		remove_objects clean_mods

fclean:		clean remove_name fclean_mods

re:		fclean all

include .libmake
