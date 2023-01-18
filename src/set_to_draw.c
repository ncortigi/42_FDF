/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:08:22 by ncortigi          #+#    #+#             */
/*   Updated: 2023/01/17 12:33:02 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	zoom(t_fdf *data)
{
	data->x1 *= data->zoom;
	data->x2 *= data->zoom;
	data->y1 *= data->zoom;
	data->y2 *= data->zoom;
}

void	shift(t_fdf *data)
{
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	data->x2 += data->shift_x;
	data->y2 += data->shift_y;
}

void	set_to_draw(float x, float y, t_fdf *data)
{
	data->x1 = x;
	data->y1 = y;
	data->z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	data->z2 = data->z_matrix[(int)data->y2][(int)data->x2];
	zoom(data);
	data->z1 *= data->z_scale;
	data->z2 *= data->z_scale;
	if (data->dim)
	{
		isometric(&data->x1, &data->y1, data->z1, data);
		isometric(&data->x2, &data->y2, data->z2, data);
	}
	shift(data);
}
