SRC = fractol_rest.c fractol.c main.c utils.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
MINLIB_DIR = -L/usr/local/lib/ -lmlx
X11_LIBS = -lX11 -lXext
NAME = fractol

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(MINLIB_DIR) ${X11_LIBS} -o $(NAME)

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all