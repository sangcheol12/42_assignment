CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = do-op
SRCS = do_op.c ft_putnbr.c calf.c
OBJS = do_op.o ft_putnbr.o calf.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

.c.o :
	$(CC) $(CFLAG) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all