SRC := srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
CC := cc
CFLAGS := -Wall -Wextra -Werror
OBJS := $(SRC:.c=.o)
NORM := norminette
TARGET = libft.a

.PHONY: clean fclean re all

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rc $@ $^
	
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
