CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -I 

NAME		=	../pipex

SRCS		=	pipex_bonus.c helpers_bonus.c strings_bonus.c \
				err_handling_bonus.c get_next_line_bonus.c helpers2_bonus.c \
				err_handling2_bonus.c get_next_line_utils_bonus.c split_bonus.c

OBJ_DIR		=	../bin/
OBJCTS		=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC_DIR		=	../headers/
INCLUDES	=	$(addprefix $(INC_DIR),pipex_bonus.h)

bonus:	$(NAME) $(INCLUDES)

$(NAME):	$(OBJCTS)
	$(CC) $(CFLAGS) $(INC_DIR) $^ -o $@
	@echo "bonus pipex is ready."

$(OBJ_DIR)%.o:	%.c ${INCLUDES}
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@