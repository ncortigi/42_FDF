/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:05:36 by ncortigi          #+#    #+#             */
/*   Updated: 2023/01/12 12:26:11 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_keys(int key)
{
	if (key >= F_SX && key <= F_DW)
		return (1);
	if (key >= ANGLE_PLUS && key <= Z_SCALE_DW)
		return (1);
	if (key == ZOOM_MINUS || key == ZOOM_PLUS || key == DIM_TYPE)
		return (1);
	return (0);
}

int	dimention(t_fdf *data)
{
	if (data->dim)
		return (0);
	return (1);
}

void	keys(int key, t_fdf *data)
{
	if (key == F_UP)
		data->shift_y -= 10;
	if (key == F_DW)
		data->shift_y += 10;
	if (key == F_SX)
		data->shift_x -= 10;
	if (key == F_DX)
		data->shift_x += 10;
	if (key == ZOOM_MINUS)
		data->zoom -= 1;
	if (key == ZOOM_PLUS)
		data->zoom += 1;
	if (key == Z_SCALE_UP)
		data->z_scale += 1;
	if (key == Z_SCALE_DW)
		data->z_scale -= 1;
	if (key == ANGLE_MINUS)
		data->angle -= 0.05;
	if (key == ANGLE_PLUS)
		data->angle += 0.05;
	if (key == DIM_TYPE)
		data->dim = dimention(data);
}

int	deal_keys(int key, t_fdf *data)
{
	if (check_keys(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		keys(key, data);
		//draw(data);
		image(data);
	}
	if (key == ESC)
		ft_close(data);
	return (0);
}
