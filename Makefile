NAME = libftprintf.a

SRCS = ft_printf.c ft_functions.c ft_hex.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.c:%.o
	$(CC) $(CFLAGE) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
