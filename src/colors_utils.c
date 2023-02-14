/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:20:13 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/13 17:10:08 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_color_matrix(t_fdf *data)
{
	int		i;

	i = 0;
	data->color_matrix = ft_calloc(sizeof(int *), (data->height + 1));
	while (i < data->height)
		data->color_matrix[i++] = (int *)malloc(sizeof(int)
				* (data->width + 1));
}

void	fill_color_matrix(int n_line, int i, char **col, t_fdf *data)
{
	free(col[0]);
	data->color_matrix[n_line][i] = ft_atoi_hex(col[1]);
	free(col[1]);
	free(col);
}

int	check_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

void	choose_color(int x, int y, t_fdf *data)
{
	if (data->color_matrix[y][x])
		data->color = data->color_matrix[y][x];
	else
		data->color = 0xBBFAFF;
}
//verde0x66FF33; //bianco0xBBFAFF;