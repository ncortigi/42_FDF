# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 12:35:06 by ncortigi          #+#    #+#              #
#    Updated: 2022/10/28 15:04:32 by ncortigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC		= ft_printaddress.c ft_putchar_int.c ft_putnbrbase_int.c \
		   ft_printf.c ft_puthex_int.c ft_putstr_int.c ft_putunsigned.c

OBJ		= $(SRC:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all
