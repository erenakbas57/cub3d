NAME = cub3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): *.o $(LIBFT) $(MLX)
	$(CC) $(FLAGS) -o $(NAME) *.o $(LIBFT) $(MLX) $(FREAMS)

*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

clean:
	rm -f *.o
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	rm -f cub3d
	@make fclean -C ./libft
	@make clean -C ./mlx

re:fclean all

.PHONY: all clean fclean re