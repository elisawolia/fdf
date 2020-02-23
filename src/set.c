/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:50:09 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/23 18:08:22 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *point, float z)
{
	point->x = (point->x - point->y) * cos(0.523599);
	point->y = (point->x + point->y) * sin(0.523599) - z;
}

void	set_points(t_dot *point, float *z, t_fdf *fdf)
{
	point->x *= fdf->zoom;
	point->y *= fdf->zoom;
	*z *= fdf->zoom_z;
	if (fdf->iso)
		isometric(point, *z);
	point->x += fdf->shift_x;
	point->y += fdf->shift_y;
}

void	color(t_fdf *fdf, t_dot point)
{
	if (fdf->map[(int)(point.y)][(int)(point.x)].col_def == 1)
	{
		fdf->color = fdf->map[(int)(point.y)][(int)(point.x)].color;
	}
	else
	{
		if (fdf->map[(int)(point.y)][(int)(point.x)].data <= -5)
			fdf->color = fdf->scheme.low;
		else if (fdf->map[(int)(point.y)][(int)(point.x)].data <= 0)
			fdf->color = fdf->scheme.fine;
		else if (fdf->map[(int)(point.y)][(int)(point.x)].data <= 5)
			fdf->color = fdf->scheme.norm;
		else if (fdf->map[(int)(point.y)][(int)(point.x)].data > 5)
			fdf->color = fdf->scheme.high;
	}
}

int		read_color(char *nums, int data, t_fdf *fdf, int *col_def)
{
	char *hex;

	hex = ft_strstr(nums, ",0x");
	if (!hex)
	{
		*col_def = 0;
		free(hex);
		if (data <= -5)
			return (fdf->scheme.low);
		if (data <= 0)
			return (fdf->scheme.fine);
		if (data <= 5)
			return (fdf->scheme.norm);
		if (data > 5)
			return (fdf->scheme.high);
	}
	*col_def = 1;
	return (hex_to_dec(hex + 3));
}
