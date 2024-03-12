NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = ft_atoi.c \
			 ft_bzero.c \
			 ft_calloc.c \
			 ft_isalnum.c \
			 ft_isalpha.c \
			 ft_isascii.c \
			 ft_isdigit.c \
			 ft_isprint.c \
			 ft_itoa.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_memset.c \
			 ft_putchar_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_putstr_fd.c \
			 ft_split.c \
			 ft_strchr.c \
			 ft_strdup.c \
			 ft_striteri.c \
			 ft_strjoin.c \
			 ft_strlcat.c \
			 ft_strlcpy.c \
			 ft_strlen.c \
			 ft_strmapi.c \
			 ft_strncmp.c \
			 ft_strnstr.c \
			 ft_strrchr.c \
			 ft_strtrim.c \
			 ft_substr.c \
			 ft_tolower.c \
			 ft_toupper.c \
			 gnl/get_next_line.c \
			 gnl/get_next_line_utils.c

MY_SOURCES_BONUS =	ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

CC = cc

$(NAME) : $(MY_OBJECTS)
	ar rc $(NAME) $(MY_OBJECTS)

clean :
	rm -f $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

bonus :
	$(MAKE) $(NAME) MY_SOURCES="$(MY_SOURCES) $(MY_SOURCES_BONUS)"

%.o : %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<