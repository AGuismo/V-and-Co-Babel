NAME	     ?=	requestSerializer

SRCS =	      	main.cpp		\
		FakeAudio.cpp		\
		Bridge.cpp

DIR.PROT=	../
DIR.SER=	../../serializer
DIR.API=	../API

MOD.INC=	-I$(DIR.PROT)/include -I$(DIR.API) -I$(DIR.SER)/include

MOD.LNK=	-L$(DIR.PROT) -lprotocol -L$(DIR.SER) -lserialize

F.C	     +=	-W -Wall --std=c++0x -Dlinux
F.I	     +=	-I./include $(MOD.INC) -I../include $(DEPS.INC)
F.L	     += $(MOD.LNK) $(DEPS.LNK) -Wl,-rpath=$(DIR.NET) -lboost_system -lboost_thread -lpthread
F.D	     +=

all:		start $(NAME)

$(NAME):	compile_mods compile

compile_mods:
		@$(ECHO) $(ES) "Compile Modules" $(EE)
		@make --no-print-directory -C ./$(DIR.PROT) all F.D=$(F.D)
		@make --no-print-directory -C ./$(DIR.SER) all F.D=$(F.D)

clean_mods:
		@$(ECHO) $(ES) "Clean Modules" $(EE)
		@make --no-print-directory -C ./$(DIR.PROT) clean
		@make --no-print-directory -C ./$(DIR.SER) clean

fclean_mods:
		@$(ECHO) $(ES) "Full clean Modules" $(EE)
		@make --no-print-directory -C ./$(DIR.PROT) fclean
		@make --no-print-directory -C ./$(DIR.SER) fclean

clean:		remove_objects clean_mods

fclean:		clean remove_name fclean_mods

re:		fclean all

include .libmake
