SOURCES	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c		\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c	\
			ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c	\
			ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c		\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c		\
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

NAME 			= libft.a

OBJECTS 		= $(SOURCES:.c=.o)

BONUS_OBJECTS 	= $(BONUS:.c=.o)

CC 				= gcc

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra

all: 			$(NAME)


$(NAME): 		$(OBJECTS)
			$(AR) rc $(NAME) $(OBJECTS)


clean:
				$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: 		clean
			$(RM) $(NAME)

re: 		fclean all

bonus: 			$(OBJECTS) $(BONUS_OBJECTS)
			$(AR) rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: 	all clean fclean re bonus