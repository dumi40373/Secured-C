##
## EPITECH PROJECT, 2025
## secured
## File description:
## Main Makefile
##

CC		=	epiclang
CFLAGS		=	-g
CPPFLAGS	=	-Iinclude

NAME	=	libhashtable.a
SRC	=	src/hashtable.c	\
		src/hash.c	\
		src/handle_table.c	\
		src/my_lib_utils.c	\
		src/my_string_utils.c	\
		src/delete_node.c	\

OBJ	=	$(SRC:src/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): %.o: src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re