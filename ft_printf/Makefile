NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_putchar.c ft_putnbr.c ft_putptr.c ft_putstr.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
