/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:07:38 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/13 17:11:55 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	count_para(char *str, char tofind)
{
	int	found;
	int	count;
	int	i;

	i = 0;
	count = 0;
	found = 0;
	if (str[0] != '\0')
	{
		while (str[i])
		{
			if (found == 0 && str[i] != tofind)
			{
				count++;
				found = 1;
			}
			else if (found == 1 && str[i] == tofind)
				found = 0;
			i++;
		}
	}
	return (count);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_para(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	matrix(int *z_line, char *line, t_fdf *data, int n_line)
{
	char	**nums;
	char	**col;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		if (check_color(nums[i]))
		{
			col = ft_split(nums[i], ',');
			free(nums[i]);
			z_line[i] = ft_atoi(col[0]);
			fill_color_matrix(n_line, i, col, data);
		}
		else
		{
			z_line[i] = ft_atoi(nums[i]);
			free(nums[i]);
			data->color_matrix[n_line][i] = 0;
		}
		i++;
	}
	free(nums);
}

void	read_map(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	create_color_matrix(data);
	data->z_matrix = ft_calloc(sizeof(int *), (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		matrix(data->z_matrix[i], line, data, i);
		i++;
		free(line);
	}
	free(line);
	close(fd);
}
