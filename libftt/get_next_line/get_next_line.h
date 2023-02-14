/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:37 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/25 12:47:26 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlenght(char *s);
char	*get_next_line(int fd);
char	*ft_strjoint(char *s1, char *s2);
int		ft1_strchr(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
#endif
