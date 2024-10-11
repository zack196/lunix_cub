NAME = cub3d
CC = cc 
CFLAG = -Wall -Wextra -Werror -fsanitize=address -g3

SRC = cub3d.c \
	  my_malloc.c \
	  gnl.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

%.o:%.c cub3d.h
	$(CC) $(CFLAG) -c $< -o $@

$(NAME):$(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re : fclean all
