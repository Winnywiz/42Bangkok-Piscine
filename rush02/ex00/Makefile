# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhaziev <skhaziev@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 08:55:48 by skhaziev          #+#    #+#              #
#    Updated: 2024/07/28 22:24:00 by skhaziev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rush-02
SRC := $(wildcard ./source/*.c)
OBJ := $(SRC:.c=.o)
INC_DIR := include

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


