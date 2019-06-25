# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 20:37:24 by lelajour          #+#    #+#              #
#    Updated: 2019/06/25 18:20:22 by lelajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

NAME = lelajour.filler

LIB.A = cd libft

PRINTF.A = cd libft/libftprintf

D_SRC = src/

D_LIBFT = $(LIB.A) $(PRINTF.A)

SRC1 =		ft_parsing.c\

SRC2=			libft/libft.a libft/libftprintf/libftprintf.a\

SRC_FILL = $(addprefix $(D_SRC), $(SRC1))

OBJ = $(SRC_FILL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C libft/libftprintf
	@cp libft/libft.a ./$(NAME)
	@cp libft/libftprintf/libftprintf.a ./$(NAME)
	@$(CC) $(NAME) $(OBJ) libft/libft.a libft/libftprintf/libftprintf.a
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
