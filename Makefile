NAME = so_long
CFLAGS = -Wall -Wextra #-Werror
CPPFLAGS= -I libft/src -I minilibx-linux/ # -I : include
CC = cc
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
SRC_PATH = src/

SRC =	main.c \
		fill_struct.c

OBJ = $(SRC:.c=.o)

LIBFT= libft/libft.a

LIBMlX = minilibx/libmlx.a

MLXFLAGS = -Lminilibx-linux/ -lmlx -lX11 -lXext

all : $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c #/headers/so_long.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

re: fclean all

fclean: clean
	rm -f $(NAME)
	make fclean -C libft #appel le make de libft

clean :
	rm -rf $(OBJ)

sanitize:
	make CFLAGS="-Wall -Wextra -Werror -g3 -fsanitize=address"

debug:
	make CFLAGS="-Wall -Wextra -Werror -g3"

FORCE :

$(LIBMLX) : FORCE
	make -C minilibx-linux

$(LIBFT) : FORCE #commande vide pour qu'il execute a chaque fois make
	make -C libft # -C : make dans un autre dossier.

.PHONY : all clean fclean re

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLXFLAGS)
