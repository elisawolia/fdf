/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/23 13:37:24 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_dot(t_fdf *fdf, t_dot point)
{
	float z;

	z = fdf->map[(int)(point.y)][(int)(point.x)].data;
	color(fdf, point);
	set_points(&point, &z, fdf);
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, point.x, point.y, fdf->color);
}

void	bresenham(t_fdf *fdf, t_dot start, t_dot end)
{
	float	x_step;
	float	y_step;
	int		max;
	float	z;
	float	z1;

	z = fdf->map[(int)(start.y)][(int)(start.x)].data;
	z1 = fdf->map[(int)(end.y)][(int)(end.x)].data;
	color(fdf, start);
	set_points(&start, &z, fdf);
	set_points(&end, &z1, fdf);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = (mod(x_step) > mod(y_step)) ? mod(x_step) : mod(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, start.x, start.y, fdf->color);
		start.x += x_step;
		start.y += y_step;
		if (start.x > 1000 || start.y > 1000 || start.y < 0 || start.x < 0)
			break ;
	}
}

void	draw(t_fdf *fdf)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (fdf->lines)
			{
				if (x < fdf->width - 1)
					bresenham(fdf, new_dot(x, y), new_dot((x + 1), y));
				if (y < fdf->height - 1)
					bresenham(fdf, new_dot(x, y), new_dot(x, (y + 1)));
			}
			else if (x < fdf->width)
				bresenham_dot(fdf, new_dot(x, y));
			x++;
		}
		y++;
	}
}
