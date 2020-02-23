/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:19:31 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/23 18:34:45 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

# define LOW_1 0xffc300
# define FINE_1 0xff5733
# define NOR_1 0xc70039
# define HIGH_1 0x900c3f

# define LOW_2 0xabedc6
# define FINE_2 0x98d9c2
# define NOR_2 0xf19a3e
# define HIGH_2 0x403233

# define LOW_3 0x9ad4d6
# define FINE_3 0xf2fdff
# define NOR_3 0xdbcbd8
# define HIGH_3 0x564787

typedef struct	s_col
{
	int		low;
	int		fine;
	int		norm;
	int		high;
}				t_col;

typedef	struct	s_dot
{
	float	x;
	float	y;
}				t_dot;

typedef	struct	s_point
{
	int		data;
	int		color;
	int		col_def;
}				t_point;

typedef struct	s_fdf
{
	int		height;
	int		width;
	t_point **map;
	int		zoom;
	int		color;
	int		zoom_z;
	int		shift_x;
	int		shift_y;
	int		iso;
	t_col	scheme;
	int		lines;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_fdf;

int				ft_fill(t_fdf *fdf, char *line, int i);
void			set_params(t_fdf *fdf);
int				ft_fill_map(t_fdf *fdf, char *file);
int				ft_read_map(t_fdf *fdf, char *file);
int				get_width(char *line);
void			bresenham(t_fdf *fdf, t_dot start, t_dot end);
void			draw(t_fdf *fdf);
void			print_menu(t_fdf *fdf);
int				check_key(int key);
void			do_key(int key, t_fdf *fdf);
void			clean_fdf(t_fdf **fdf);
int				deal_key(int key, t_fdf *fdf);
void			set_params(t_fdf *fdf);
int				main(int argc, char **argv);
void			isometric(t_dot *point, float z);
void			set_points(t_dot *point, float *z, t_fdf *fdf);
void			color(t_fdf *fdf, t_dot point);
float			mod(float a);
t_dot			new_dot(int x, int y);
double			ft_pow(double n, int pow);
int				hex_to_dec(char *hex);
void			ft_clear(char **buf, int w);
int				read_color(char *nums, int data, t_fdf *fdf, int *col_def);

#endif
