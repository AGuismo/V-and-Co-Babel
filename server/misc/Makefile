CALL.DIR=	./call
AUTH.DIR=	./auth
CHAT.DIR=	./chat
FRIEND.DIR=	./friends
PERSO.DIR=	./perso

install:
	@make --no-print-directory -C $(CALL.DIR) install F.D=$(F.D)
	@make --no-print-directory -C $(AUTH.DIR) install F.D=$(F.D)
	@make --no-print-directory -C $(CHAT.DIR) install F.D=$(F.D)
	@make --no-print-directory -C $(FRIEND.DIR) install F.D=$(F.D)
	@make --no-print-directory -C $(PERSO.DIR) install F.D=$(F.D)

clean:
	@make --no-print-directory -C $(CALL.DIR) clean
	@make --no-print-directory -C $(AUTH.DIR) clean
	@make --no-print-directory -C $(CHAT.DIR) clean
	@make --no-print-directory -C $(FRIEND.DIR) clean
	@make --no-print-directory -C $(PERSO.DIR) clean

fclean:
	@make --no-print-directory -C $(CALL.DIR) fclean
	@make --no-print-directory -C $(AUTH.DIR) fclean
	@make --no-print-directory -C $(CHAT.DIR) fclean
	@make --no-print-directory -C $(FRIEND.DIR) fclean
	@make --no-print-directory -C $(PERSO.DIR) fclean


