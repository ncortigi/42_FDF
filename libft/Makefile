# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:39:59 by ncortigi          #+#    #+#              #
#    Updated: 2022/12/14 16:11:39 by ncortigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART_1_2	= ft_atoi.c ft_isdigit.c ft_memset.c ft_strlcpy.c ft_substr.c \
		  ft_bzero.c ft_isprint.c ft_split.c ft_strlen.c ft_tolower.c \
		  ft_calloc.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_toupper.c \
		  ft_isalnum.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
		  ft_isalpha.c ft_memcpy.c ft_strjoin.c ft_strrchr.c \
		  ft_isascii.c ft_memmove.c ft_strlcat.c ft_strtrim.c \
		  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c \

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ 		= $(PART_1_2:.c=.o)

BONUS_OBJ	= $(BONUS:.c=.o)


CC		= gcc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.


all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

bonus:		$(OBJ) $(BONUS_OBJ)
			ar rcs $(NAME) $(BONUS_OBJ)

clean:
		$(RM) $(OBJ) $(BONUS_OBJ)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all
