##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC		=	main.c \
			get_next_line.c

OBJ		=	$(SRC:.c=.o)

NAME	=	getnl

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g3 $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
