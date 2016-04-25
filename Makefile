# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/20 18:01:12 by eebersol          #+#    #+#              #
#    Updated: 2016/03/14 21:48:27 by lede-ser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	fillit

_SRCS		=	fillit.c \
				ft_check_coord.c \
				ft_check_tetri.c \
				ft_error.c \
				ft_init_env.c \
				ft_read_map.c \
				ft_check_place.c \
				ft_place_tetri.c \
				ft_create_map.c \
				ft_update_tetri.c \
				ft_create_ltetri.c \
				ft_reset_param.c

SRCS			=	$(addprefix srcs/,$(_SRCS))
LIBFT		= 	-Llibft -lft -Ilibft
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(CFLAGS)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(SRCS) -Iincludes -o $(NAME) $(LIBFT)
	@echo $(NAME) "compiled"

clean:
	@make clean -C libft
	@/bin/rm -rf bin
	@echo "Clean all .o"

fclean:
	@make fclean -C libft
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o  .a"

re: fclean all

.PHONY: all, clean, fclean, re
