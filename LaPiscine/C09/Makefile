CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a

SRC_PATH = ./srcs/
HEADER = ./includes/
SRC = $(SRC_PATH)ft_putchar.c $(SRC_PATH)ft_putstr.c \
	$(SRC_PATH)ft_strcmp.c $(SRC_PATH)ft_strlen.c $(SRC_PATH)ft_swap.c
OBJS = $(SRC_PATH)ft_putchar.o $(SRC_PATH)ft_putstr.o $(SRC_PATH)ft_strcmp.o \
	   $(SRC_PATH)ft_strlen.o $(SRC_PATH)ft_swap.o

all: $(LIB)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(HEADER) -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)

re: fclean all