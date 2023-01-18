/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:43 by ncortigi          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:35 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
    char	*data2;

	data2 = data->img->data + (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
	*(unsigned int*)data2 = color;
}

int	image(t_fdf *data)
{
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, LARG_FIN, ALT_FIN);
	data->img->data = mlx_get_data_addr(data->img->mlx_img, 
                        &data->img->bits_per_pixel, 
                        &data->img->line_length, 
                        &data->img->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	key_map(data);
	return (0);
}