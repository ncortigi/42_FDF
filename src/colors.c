/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:20:13 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/06 12:40:44 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_color_matrix(t_fdf *data)
{
	int		i;

	i = 0;
	data->color_matrix = ft_calloc(sizeof(int *), (data->height + 1));
	while (i <= data->height)
		data->color_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
}

int		check_color(char *str)
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
	//if ((data->z1 || data->z2) && data->color_matrix[x][y] == 0)
	//	data->color = 0xfc0345;
	if (data->color_matrix[x][y] == 0)
		data->color = 0xBBFAFF;//verde0x66FF33; //bianco0xBBFAFF;
	else if (data->color_matrix[x][y] != 0)
		data->color = data->color_matrix[x][y];
	//ft_printf("\ncolore scelto: %d\n", data->color_matrix[x][y]);
}
