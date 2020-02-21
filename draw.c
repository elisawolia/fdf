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

#include "stdio.h"

#define MOD(a) ((a >= 0) ? a: -a)

void isometric(float *x, float *y, int z)
{
	int x1;
	int y1;

	x1 = *x;
	y1 = *y;
	*x = (x1 - y1) * cos(0.523599);
	*y = (x1 + y1) * sin(0.523599) - z;
}

void bresenham(t_fdf *fdf, float x, float y, float x1, float y1)
{
	float x_step;
	float y_step;
	float max;
	int z;
	int z1;

	z = fdf->map[(int)y][(int)x];
	z1 = fdf->map[(int)y1][(int)x1];



	x *= fdf->zoom;
	y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
	z *= fdf->zoom;
	z1 *= fdf->zoom;

	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x_step = x1 - x;
	y_step = y1 - y;

	fdf->color = (z) ? 0xe80c0c : 0xffffff;


	x_step = (x_step >= 0) ? x_step : -x_step;
	y_step = (y_step >= 0) ? y_step : -y_step;
	printf("X STEP IS %f\n", x_step);
	printf("Y STEP IS %f\n", y_step);
	if (x_step > y_step)
		max = x_step;
	else
		max = y_step;
	x_step /= max;
	y_step /= max;
	
	ft_putstr("\nFIRST IS\n");
	ft_putnbr((int)(x - x1));
	ft_putstr("\nSECOND IS\n");
	ft_putnbr((int)(y - y1));

	printf("\nX IS %f\n", x);
	printf("X1 IS %f\n", x1);
	printf("Y IS %f\n", y);
	printf("Y1 IS %f\n", y1);
	printf("X STEP IS %f\n", x_step);
	printf("Y STEP IS %f\n", y_step);
	printf("\nX IS %f\n", x);
	printf("MAX %f\n", max);


	while ((MOD((int)(x - x1)) || MOD((int)(y - y1))))
	{

		//ft_putstr("\nSECOND IS\n");
		//printf("%f\n",(y - y1));
		//ft_putnbr(y);
		//ft_putchar('\n');
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
		x += x_step;
		y += y_step;
		//if (x > 1000 || y > 1000 || y < 0 || x < 0)
		//	return ;
	}
}

void	draw(t_fdf *fdf)
{
	float i;
	float j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_putstr("I");
			ft_putnbr(i);
			ft_putstr("J");
			ft_putnbr(j);
			if (j < fdf->width - 1)
				bresenham(fdf, j, i, (j + 1), i);
			if (i < fdf->height - 1)
			{
				printf("IM IN\n");
				bresenham(fdf, j, i, j, (i + 1));
				printf("IM OUT\n");
			}
			
			j++;
		}
		i++;
	}
}