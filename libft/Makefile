NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I headers

PRINTF_PATH = ft_printf/
PRINTF = $(PRINTF_PATH)/libftprintf.a
SRC_PATH = src/
OBJ_PATH = obj/

SRC = 	ft_atoi.c\
		ft_lstadd_back_bonus.c\
		ft_memcmp.c\
		ft_putstr_fd.c\
		ft_strncmp.c\
		ft_blen.c\
		ft_lstadd_front_bonus.c\
		ft_memcpy.c\
		ft_split.c\
		ft_strnstr.c\
		ft_bzero.c\
		ft_lstclear_bonus.c\
		ft_memmove.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_calloc.c\
		ft_lstdelone_bonus.c\
		ft_memset.c\
		ft_strdup.c\
		ft_strtrim.c\
		ft_isalnum.c\
		ft_lstiter_bonus.c\
		ft_printf.c\
		ft_striteri.c\
		ft_substr.c\
		ft_isalpha.c\
		ft_lstlast_bonus.c\
		ft_putchar_fd.c\
		ft_strjoin.c\
		ft_tolower.c\
		ft_isascii.c\
		ft_lstmap_bonus.c\
		ft_putendl_fd.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_isdigit.c\
		ft_lstnew_bonus.c\
		ft_putnbr_adress.c\
		ft_strlcpy.c\
		get_next_line.c\
		ft_isprint.c\
		ft_lstsize_bonus.c\
		ft_putnbr_base.c\
		ft_strlen.c\
		get_next_line_utils.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_putnbr_fd.c\
		ft_strmapi.c




OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all : $(OBJ_PATH) $(NAME)

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all bonus

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
