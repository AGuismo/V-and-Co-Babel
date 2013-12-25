NAME	     ?=	database_unit_test

SRCS =	      	main.cpp		\
		empty.cpp		\
		multipleUsers.cpp	\
		requestTest1.cpp	\
		singleUser.cpp		\

DIR.API=	../../../protocol/API
DIR.DB=		../
DIR.SERIALIZER=	../../../serializer/
DIR.PROTOCOL=	../../../protocol/

DEPS.INC=
DEPS.LNK=

MOD.INC=	-I$(DIR.DB)/include -I$(DIR.PROTOCOL)/include -I$(DIR.SERIALIZER)/include -I$(DIR.API)
MOD.LNK=	-L$(DIR.DB) -ldb -L$(DIR.PROTOCOL) -lprotocol -L$(DIR.SERIALIZER) -lserialize

F.C	     +=	-W -Wall
F.I	     += $(MOD.INC) $(DEPS.INC) -I./include
F.L	     += $(MOD.LNK) $(DEPS.LNK) -lboost_system -lboost_thread -lpthread
F.D	     +=

all:		start $(NAME)

$(NAME):	compile_mods compile

compile_mods:
		@$(ECHO) $(ES) "Compile Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) all F.D=$(F.D)
		@make --no-print-directory -C $(DIR.SERIALIZER) all F.D=$(F.D)
		@make --no-print-directory -C $(DIR.PROTOCOL) all F.D=$(F.D)

compile_deps:
		@$(ECHO) $(ES) "Compile Dependancies" $(EE)

clean_mods:
		@$(ECHO) $(ES) "Clean Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) clean
		@make --no-print-directory -C $(DIR.SERIALIZER) clean
		@make --no-print-directory -C $(DIR.PROTOCOL) clean

clean_deps:
		@$(ECHO) $(ES) "Clean Dependancies" $(EE)

fclean_mods:
		@$(ECHO) $(ES) "Full clean Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) fclean
		@make --no-print-directory -C $(DIR.SERIALIZER) fclean
		@make --no-print-directory -C $(DIR.PROTOCOL) fclean

fclean_deps:
		@$(ECHO) $(ES) "Full clean Dependancies" $(EE)

clean:		remove_objects clean_mods

fclean:		clean remove_name fclean_mods

re:		fclean all

include .libmake
