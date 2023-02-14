/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:38:59 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/13 17:12:22 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libftt/libft.h"
# include "../libftprintf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define ALT_FIN 995
# define LARG_FIN 1920

# define F_DX 65363
# define F_SX 65361
# define F_UP 65362
# define F_DW 65364

# define Z_SCALE_UP 65431
# define Z_SCALE_DW 65433

# define ANGLE_PLUS 65430
# define ANGLE_MINUS 65432

# define ZOOM_PLUS 65451
# define ZOOM_MINUS 65453

# define DIM_TYPE 65421
# define ESC 65307

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		bits_pixel;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		**color_matrix;
	int		shift_x;
	int		shift_y;
	int		dim;
	double	angle;
	float	z_scale;
	float	x1;
	float	y1;
	float	z1;
	float	x2;
	float	y2;
	float	z2;
	t_img	*img;
}		t_fdf;

void	fill_color_matrix(int n_line, int i, char **col, t_fdf *data);
int		check_color(char *str);
void	create_color_matrix(t_fdf *data);
void	choose_color(int x, int y, t_fdf *data);
void	read_map(char *file_name, t_fdf *data);
void	set_to_draw(float x, float y, t_fdf *data);
void	draw(t_fdf *data);
int		deal_keys(int key, t_fdf *data);
int		ft_close(t_fdf *data);
void	key_map(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		image(t_fdf *data);

#endif
