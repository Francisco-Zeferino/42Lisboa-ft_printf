SourceFiles = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putnbr_unsigned.c ft_strlen.c ft_getaddress.c

Objects = $(SourceFiles:.c=.o)

NAME = libftprintf.a
CC = cc
LIB = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
all: $(NAME)

$(NAME): $(Objects)
	$(LIB) $(NAME) $(Objects)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(Objects)

fclean : clean
	$(RM) $(NAME)

re : fclean all
