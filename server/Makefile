NAME	     ?=	server_babel

SRCS =	      	main.cpp			\
		Application.cpp			\
		Server.cpp			\
		Client.cpp			\
		Administrator.cpp		\
		Maintenance.cpp			\
		MaintenanceConnection.cpp	\
		Env.cpp				\
						\
		PluginException.cpp		\
		RequestPlugin.cpp		\
		RequestCaller.cpp		\

DIR.DB=		./database
DIR.INIPARSER=	../IniParser
DIR.SERIALIZER=	../serializer/
DIR.PROTOCOL=	../protocol/
DIR.DYNAMIC=	../MDynamic/MDynamic
DIR.PLUGS=	./misc

DEPS.INC=
DEPS.LNK=

MOD.INC=	-I$(DIR.DB)/include -I$(DIR.PROTOCOL)/include -I$(DIR.PROTOCOL)/API
MOD.INC+=	-I$(DIR.INIPARSER)/include -I$(DIR.SERIALIZER)/include -I$(DIR.DYNAMIC)/include
MOD.LNK=	-Wl,--whole-archive -L$(DIR.PROTOCOL) -lprotocol -Wl,-export-dynamic
MOD.LNK+=	-L$(DIR.DB) -ldb -L$(DIR.SERIALIZER) -lserialize
MOD.LNK+=	-L$(DIR.INIPARSER) -liniparser -L$(DIR.DYNAMIC) -lMDynamic -Wl,--no-whole-archive

F.C	     +=	-W -Wall
F.I	     += $(MOD.INC) $(DEPS.INC)
F.L	     += $(MOD.LNK) $(DEPS.LNK) -lboost_system -lboost_thread -lboost_filesystem -lpthread -ldl
F.D	     +=

all:		start $(NAME)

plugins:
		@make --no-print-directory -C $(DIR.PLUGS) install F.D=$(F.D)

$(NAME):	compile_mods compile

compile_mods:
		@$(ECHO) $(ES) "Compile Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) all F.D=$(F.D)
		@make --no-print-directory -C $(DIR.INIPARSER) all F.D=$(F.D)
		@make --no-print-directory -C $(DIR.SERIALIZER) all F.D=$(F.D)
		@make --no-print-directory -C $(DIR.PROTOCOL) all F.D=$(F.D)
		@make --no-print-directory -C $(DIR.DYNAMIC) all F.D=$(F.D)

compile_deps:
		@$(ECHO) $(ES) "Compile Dependancies" $(EE)

clean_mods:
		@$(ECHO) $(ES) "Clean Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) clean
		@make --no-print-directory -C $(DIR.INIPARSER) clean
		@make --no-print-directory -C $(DIR.SERIALIZER) clean
		@make --no-print-directory -C $(DIR.PROTOCOL) clean
		@make --no-print-directory -C $(DIR.DYNAMIC) clean

clean_deps:
		@$(ECHO) $(ES) "Clean Dependancies" $(EE)

fclean_mods:
		@$(ECHO) $(ES) "Full clean Modules" $(EE)
		@make --no-print-directory -C $(DIR.DB) fclean
		@make --no-print-directory -C $(DIR.INIPARSER) fclean
		@make --no-print-directory -C $(DIR.SERIALIZER) fclean
		@make --no-print-directory -C $(DIR.PROTOCOL) fclean
		@make --no-print-directory -C $(DIR.DYNAMIC) fclean

fclean_deps:
		@$(ECHO) $(ES) "Full clean Dependancies" $(EE)

clean:		remove_objects clean_mods

clean_plugins:
		@make --no-print-directory -C $(DIR.PLUGS) clean

fclean:		clean remove_name fclean_mods

fclean_plugins:
		@make --no-print-directory -C $(DIR.PLUGS) fclean

re:		fclean all

re_plugins:	fclean_plugins plugins

include .libmake
