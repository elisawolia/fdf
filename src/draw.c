/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/21 12:45:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MOD(a) ((a >= 0) ? a: -a)

void isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void bresenham_dot(t_fdf *fdf, float x, float y)
{
	float z;

	z = fdf->map[(int)y][(int)x].data;

	if (fdf->map[(int)y][(int)x].col_def == 1)
	{
		fdf->color = fdf->map[(int)y][(int)x].color;
	}
	else
	{
		if (fdf->map[(int)y][(int)x].data <= -5)
			fdf->color = fdf->scheme.low;
		else if (fdf->map[(int)y][(int)x].data <= 0)
			fdf->color = fdf->scheme.fine;
		else if (fdf->map[(int)y][(int)x].data <= 5)
			fdf->color = fdf->scheme.norm;
		else if (fdf->map[(int)y][(int)x].data > 5)
			fdf->color = fdf->scheme.high;
	}
	

	x *= fdf->zoom;
	y *= fdf->zoom;
	z *= fdf->zoom_z;

	if (fdf->iso)
		isometric(&x, &y, z);

	x += fdf->shift_x;
	y += fdf->shift_y;
	
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
}

void bresenham(t_fdf *fdf, float x, float y, float x1, float y1)
{
	float x_step;
	float y_step;
	int max;
	float z;
	float z1;

	z = fdf->map[(int)y][(int)x].data;
	z1 = fdf->map[(int)y1][(int)x1].data;
	
	if (fdf->map[(int)y][(int)x].col_def == 1)
	{
		fdf->color = fdf->map[(int)y][(int)x].color;
	}
	else
	{
		if (fdf->map[(int)y][(int)x].data <= -5)
			fdf->color = fdf->scheme.low;
		else if (fdf->map[(int)y][(int)x].data <= 0)
			fdf->color = fdf->scheme.fine;
		else if (fdf->map[(int)y][(int)x].data <= 5)
			fdf->color = fdf->scheme.norm;
		else if (fdf->map[(int)y][(int)x].data > 5)
			fdf->color = fdf->scheme.high;
	}
	

	x *= fdf->zoom;
	y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
	z *= fdf->zoom_z;
	z1 *= fdf->zoom_z;


	if (fdf->iso)
	{
		isometric(&x, &y, z);
		isometric(&x1, &y1, z1);
	}

	x += fdf->shift_x;
	y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	
	max = (MOD(x_step) > MOD(y_step)) ? MOD(x_step) : MOD(y_step);

	x_step /= max;
	y_step /= max;

	while ((int)(x - x1)||(int)(y - y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
		x += x_step;
		y += y_step;
		if (x > 1000 || y > 1000 || y < 0 || x < 0)
			break ;
	}
}


void	draw(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->lines)
			{
				if (j < fdf->width - 1)
					bresenham(fdf, j, i, (j + 1), i);
				if (i < fdf->height - 1)
					bresenham(fdf, j, i, j, (i + 1));
			}
			else
			{
				if (j < fdf->width)
					bresenham_dot(fdf, j, i);
			}
			j++;
		}
		i++;
	}
}