NAME	=	pipex

all:
	@make -C pipex_mandatory

bonus:
	@make -C pipex_bonus

clean:
	@rm -rf bin/
	@echo Cleaned

fclean: clean
	@rm -rf $(NAME)
	@echo Erased

re:	fclean all
	@echo Recompiled.

.PHONY: all bonus clean fclean re