NAME = cub3d
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit
RM = rm -f

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): *.o $(LIBFT) $(MLX)
	$(CC) $(FLAGS) -o $(NAME) *.o $(LIBFT) $(MLX) $(FREAMS)
	$(RM) *.o
	
*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

clean:
	$(RM) *.o
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	$(RM) cub3d
	@make fclean -C ./libft
	@make clean -C ./mlx

re:fclean all

.PHONY: all clean fclean re