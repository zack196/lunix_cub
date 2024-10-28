NAME=cub3d

CC=cc 

CFLAG=-Wall -Wextra -Werror #-fsanitize=address -g3 

SRC = main.c libft.c my_malloc.c tmp.c events.c map.c player.c ray.c utiles.c

OBJ=$(SRC:.c=.o)

all:$(NAME)

$(OBJ) : cub3d.h

%.o: %.c
	$(CC) $(CFLAG) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all