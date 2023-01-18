# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 17:00:09 by ncortigi          #+#    #+#              #
#    Updated: 2023/01/18 15:51:18 by ncortigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= src/*c

OBJ		= $(SRC:.c=.o)

LIBFT	= libft/libft.a

LIBFT_PF= libftprintf/libftprintf.a

INCLUDES= libft/libft.a minilibx-linux/libmlx.a libftprintf/libftprintf.a

CC		= gcc
RM		= rm -f
CFLAGS	= -g -Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -sC minilibx-linux all
			make -sC libft all
			make -sC libftprintf all
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) -lXext -lX11 -lm

all:		$(NAME)

clean:
		make -sC ./minilibx-linux clean
		make -sC ./libft clean
		make -sC libftprintf clean
		$(RM) $(NAME)

fclean:		clean
			$(RM) $(NAME) $(LIBFT) $(LIBFT_PF)

re:		fclean all
