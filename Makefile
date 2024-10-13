NAME = cub3d
CC = cc 
CFLAG = -Wall -Wextra -Werror -fsanitize=address -g3

SRC = cub3d.c \
	  my_malloc.c \
	  gnl.c \
	  parce.c \
	  ft_libft.c 

OBJ = $(SRC:.c=.o)

all:$(NAME)

%.o: %.c cub3d.h
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re : fclean all
