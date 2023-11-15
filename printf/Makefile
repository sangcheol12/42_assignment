NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
		./libft/ft_strlen.c \
		./libft/ft_strchr.c \
		./libft/ft_itoa.c \
		./libft/ft_strjoin.c \
		./libft/ft_strlcpy.c \
		./libft/ft_strlcat.c
OBJS = $(SRCS:.c=.o)
AR = ar -rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft