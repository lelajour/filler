# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 20:37:24 by lelajour          #+#    #+#              #
#    Updated: 2019/07/04 03:43:11 by lelajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

NAME = lelajour.filler

D_SRC = src/

D_LIBFT = libft/

D_LIBFTPRINTF = libft/libftprintf/

SRC1 =		ft_parsing.c\

SRC2 =		libft.a\

SRC3 =		libftprintf.a\

SRC_FILL = $(addprefix $(D_SRC), $(SRC1))

SRC_LIB.A = $(addprefix $(D_LIBFT), $(SRC2))

SRC_PRINTF.A = $(addprefix $(D_LIBFTPRINTF), $(SRC3))

OBJ = $(SRC_FILL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C libft/libftprintf
	@$(CC) -g -o $(NAME) $(OBJ) $(SRC_LIB.A) $(SRC_PRINTF.A)
	@echo "\033[0;32m✅️    $(NAME) executable created."

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[0;32m✅️    $@ created."

clean:
	@make clean -C libft
	@make clean -C libft/libftprintf
	@rm -f $(OBJ)
	@echo "\033[0;31m🗑️    Deleting object files."

fclean: clean
	@rm -f libft/libft.a
	@rm -f libft/libftprintf/libftprintf.a
	@rm -f $(NAME)
	@echo "\033[0;31m🗑️    Deleting $(NAME) executable."

re: fclean all
