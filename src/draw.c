/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:57:50 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/13 16:33:50 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	choice(float a, float b)
{
	float	step;

	if (a > b)
		step = a;
	else
		step = b;
	return (step);
}

void	bresenham(float x, float y, t_fdf *data)
{
	float	step;
	float	dx;
	float	dy;
	int		color;

	set_to_draw(x, y, data);
	color = data->color;
	dx = data->x2 - data->x1;
	dy = data->y2 - data->y1;
	step = choice(fabsf(dx), fabsf(dy));
	dx = dx / step;
	dy = dy / step;
	while ((int)(data->x1 - data->x2) || (int)(data->y1 - data->y2))
	{
		if (data->x1 >= LARG_FIN || data->y1 >= ALT_FIN)
			break ;
		if (data->x1 < 0 || data->y1 < 0)
			break ;
		my_mlx_pixel_put(data, data->x1, data->y1, color);
		data->x1 += dx;
		data->y1 += dy;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				data->x2 = x + 1;
				data->y2 = y;
				bresenham(x, y, data);
			}
			if (y < data->height - 1)
			{
				data->x2 = x;
				data->y2 = y + 1;
				bresenham(x, y, data);
			}
		}
	}
}
