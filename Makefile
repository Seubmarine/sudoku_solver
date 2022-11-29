CC = cc
NAME = sudoku_solver
CFLAGS = -Wall -Wextra -Werror

SRCS = verify.c solver.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
