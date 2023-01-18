/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:49:42 by ncortigi          #+#    #+#             */
/*   Updated: 2023/01/09 13:02:00 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_map(t_fdf *data)
{
	char	*menu;

	menu = "To move the image use arrow up, down, left, right";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xBBFAFF, menu);
	menu = "To zoom use +, - (numeric keypad)";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0xBBFAFF, menu);
	menu = "To rotate use 4, 6 (numeric keypad)";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xBBFAFF, menu);
	menu = "To change the z-scale use 8, 2 (numeric keypad)";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0xBBFAFF, menu);
	menu = "To change projection use Enter (numeric keypad)";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0xBBFAFF, menu);
}
