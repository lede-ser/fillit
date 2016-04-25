#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 13:01:06 by eebersol          #+#    #+#              #
#    Updated: 2016/02/23 19:59:17 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

SRCS 	= ft_memset.c \
	   	ft_bzero.c \
	   	ft_memcpy.c \
	   	ft_memccpy.c \
	   	ft_memmove.c \
	   	ft_memchr.c \
	   	ft_memcmp.c \
	   	ft_strlen.c \
	   	ft_strdup.c \
	   	ft_strcpy.c \
	   	ft_strncpy.c \
	   	ft_strcat.c \
	   	ft_strncat.c \
	   	ft_strlcat.c \
	   	ft_strrchr.c \
		ft_strchr.c \
	   	ft_strstr.c \
	   	ft_strnstr.c \
	   	ft_strcmp.c \
	   	ft_strncmp.c \
	   	ft_atoi.c \
	   	ft_isalpha.c \
	   	ft_isdigit.c \
	   	ft_isalnum.c \
	   	ft_isascii.c \
	   	ft_isprint.c \
	   	ft_toupper.c \
	   	ft_tolower.c \
	   	ft_memalloc.c \
	   	ft_strdel.c \
	   	ft_strclr.c \
	   	ft_striter.c \
	   	ft_strequ.c \
		ft_strnequ.c \
	   	ft_putchar.c \
	   	ft_putstr.c \
	   	ft_putendl.c \
	   	ft_putnbr.c \
	   	ft_putchar_fd.c \
	   	ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_strsub.c \
		ft_memdel.c \
		ft_putnbr_fd.c \
		ft_strjoin.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strtrim.c \
		ft_strnew.c \
		ft_strmapi.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_positive.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstadd.c \
		ft_strlenchar.c \
		ft_part_nbr.c \
		ft_len_int.c \
		ft_sign_int.c \
		ft_chartrim.c \
		ft_isblank.c \
		ft_isspace.c \
		ft_xdigit.c \
		ft_iscntrl.c \
		ft_sqrt.c

OBJS 	= $(subst .c,.o,$(SRCS))

CFLAGS 	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	:
	@gcc -c $(CFLAGS) $(SRCS) -I . 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Lib compiled"

$(OBJS) : $(NAME)
	@gcc $(CFLAGS) -c $(SRCS)

clean	: 
	@rm -rf $(OBJS)
	@echo "clean .o - Libft"

fclean	: clean
	@echo "Clean all Libft"
	@/bin/rm -f $(NAME)

re		: fclean all
