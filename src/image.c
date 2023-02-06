/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:43 by ncortigi          #+#    #+#             */
/*   Updated: 2023/01/30 18:21:41 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*i;
	int		y1;

	y1 = y * data->img->line_len;
	i = data->img->data + (y1 + x * (data->img->bits_pixel / 8));
	*(unsigned int *)i = color;
}

int	image(t_fdf *data)
{
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, LARG_FIN, ALT_FIN);
	data->img->data = mlx_get_data_addr(data->img->mlx_img,
			&data->img->bits_pixel,
			&data->img->line_len,
			&data->img->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	key_map(data);
	return (0);
}
