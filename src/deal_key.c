/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:22:12 by ahandsom          #+#    #+#             */
/*   Updated: 2020/02/23 18:13:59 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_key(int key)
{
	if (key == 124 || key == 123 || key == 125 || key == 126 || key == 27
		|| key == 24 || key == 6 || key == 7 || key == 12 || key == 13
		|| key == 53 || key == 18 || key == 19 || key == 20 || key == 37
		|| key == 40)
		return (1);
	return (0);
}

void	do_key(int key, t_fdf *fdf)
{
	if (key == 124)
		fdf->shift_x += 20;
	if (key == 123)
		fdf->shift_x -= 20;
	if (key == 125)
		fdf->shift_y += 20;
	if (key == 126)
		fdf->shift_y -= 20;
	if (key == 27)
		fdf->zoom -= 1;
	if (key == 24)
		fdf->zoom += 1;
	if (key == 6)
		fdf->zoom_z += 1;
	if (key == 7)
		fdf->zoom_z -= 1;
	if (key == 12)
		fdf->iso = 1;
	if (key == 13)
		fdf->iso = 0;
	if (key == 37)
		fdf->lines = 0;
	if (key == 40)
		fdf->lines = 1;
}

void	color_key(int key, t_fdf *fdf)
{
	if (key == 18)
	{
		fdf->scheme.low = LOW_1;
		fdf->scheme.fine = FINE_1;
		fdf->scheme.norm = NOR_1;
		fdf->scheme.high = HIGH_1;
	}
	if (key == 19)
	{
		fdf->scheme.low = LOW_2;
		fdf->scheme.fine = FINE_2;
		fdf->scheme.norm = NOR_2;
		fdf->scheme.high = HIGH_2;
	}
	if (key == 20)
	{
		fdf->scheme.low = LOW_3;
		fdf->scheme.fine = FINE_3;
		fdf->scheme.norm = NOR_3;
		fdf->scheme.high = HIGH_3;
	}
}

int		deal_key(int key, t_fdf *fdf)
{
	if (check_key(key))
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		print_menu(fdf);
		do_key(key, fdf);
		color_key(key, fdf);
		draw(fdf);
	}
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf);
		exit(0);
	}
	return (0);
}
