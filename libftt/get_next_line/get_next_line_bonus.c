/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:37:23 by ncortigi          #+#    #+#             */
/*   Updated: 2022/11/25 12:48:15 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reset(char *mem)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	if (!mem[i])
	{
		free(mem);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlenght(mem) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (mem[i])
		str[j++] = mem[i++];
	str[j] = '\0';
	free(mem);
	return (str);
}

char	*find_line(char *mem)
{
	int		i;
	char	*str;

	i = 0;
	if (!mem)
		return (NULL);
	while (mem[i] && mem[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (mem[i] != '\0' && mem[i] != '\n')
	{
		str[i] = mem[i];
		i++;
	}
	if (mem[i] == '\n')
	{
		str[i] = mem[i];
		str[++i] = '\0';
	}
	str[i] = '\0';
	return (str);
}

char	*leggi(int fd, char *memoria)
{
	int		ret;
	char	*buffer;

	ret = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft1_strchr(memoria) == 0 && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		memoria = ft_strjoint(memoria, buffer);
	}
	free(buffer);
	return (memoria);
}

char	*get_next_line(int fd)
{
	static char	*memoria[1024];
	char		*linea;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (memoria[fd] != NULL)
		{
			free(memoria[fd]);
			memoria[fd] = NULL;
		}
		return (NULL);
	}
	memoria[fd] = leggi(fd, memoria[fd]);
	if (!memoria[fd][0])
	{
		free(memoria[fd]);
		memoria[fd] = NULL;
		return (NULL);
	}
	linea = find_line(memoria[fd]);
	memoria[fd] = ft_reset(memoria[fd]);
	return (linea);
}
