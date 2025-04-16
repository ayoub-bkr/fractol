SRC = fractol.c main.c utils.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lX11 -lXext -lmlx
NAME = fractol

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -Lminilibx-linux -lX11 -lXext -lmlx  -o $(NAME)

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all