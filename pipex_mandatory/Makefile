CC			=	cc -fsanitize=address -g
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -I

NAME		=	../pipex

SRCS		=	err_handling.c ft_pipex.c helpers.c split.c strings.c

OBJ_DIR		=	../bin/
OBJCTS		=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC_DIR		=	../headers/
INCLUDES	=	$(addprefix $(INC_DIR),pipex.h)

all:	$(NAME) $(INCLUDES)

$(NAME): $(OBJCTS)
	$(CC) $(CFLAGS) $(INC_DIR) $^ -o $@
	@echo "mandatory pipex is ready."

$(OBJ_DIR)%.o:	%.c ${INCLUDES}
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@