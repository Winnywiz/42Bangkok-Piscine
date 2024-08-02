NAME := bsq
SRC := $(wildcard ./srcs/*.c)
OBJ := $(SRC:.c=.o)
INC_DIR := includes

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)
NFLAGS := -R CheckForbiddenSourceHeader -R CheckDefine 
NORM := norminette

.PHONY: all clean fclean norm

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@  

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
norm:
	$(NORM) $(NFLAGS) $(SRC) $(INC_DIR)
