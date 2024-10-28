


CC = cc
UNAME := $(shell uname)

# ifeq ($(UNAME), darwin)
MLXFLAG := ./libraries/mlx/libmlx.a -framework OpenGL -framework AppKit
MLXINC := -I./libraries/mlx/minilibx_opengl
# else
# MLXFLAG := ./libraries/minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
# MLXINC := -I./libraries/minilibx-linux
# endif

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g $(MLXINC)
GET_NEXT_LINE = includes/get_next_line
SRC = main.c utils.c parcing.c filling.c $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = cub3d

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@printf " \033[1;32m[FILE READY]\033[0m\n"

clean:
	rm -rf $(OBJ)
	@printf " \033[31m[CLEANING DONE]\033[0m\n"

fclean: clean
	rm -rf $(NAME)
	@printf " \033[31m[FULLCLEAN DONE]\033[0m\n"

re: fclean all

.SECONDARY: $(OBJ)