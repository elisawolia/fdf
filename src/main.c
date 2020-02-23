/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:09:48 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/18 14:18:02 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_key(int key)
{
	if (key == 124 || key == 123 || key == 125 || key == 126 || key == 27 || key == 24 || key == 6 || key == 7
		|| key == 12 || key == 13 || key == 53 || key == 18 || key == 19 || key == 20 || key == 37 || key == 40)
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
	if (key == 37)
		fdf->lines = 0;
	if (key == 40)
		fdf->lines = 1;
}

void clean_fdf(t_fdf **fdf)
{
	int i;

	i = 0;
	while ((*fdf)->map[i])
	{
		free((*fdf)->map[i]);
		i++;
	}
	free((*fdf)->map);
	free(*fdf);
}

int deal_key(int key, t_fdf *fdf)
{
	if (check_key(key))
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		print_menu(fdf);
		do_key(key, fdf);
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

void	set_params(t_fdf *fdf)
{
	fdf->width = 0;
	fdf->height = 0;
	fdf->zoom = 30;
	fdf->zoom_z = 1;
	fdf->shift_x = 400;
	fdf->shift_y = 400;
	fdf->color = 0xffffff;
	fdf->iso = 1;
	fdf->scheme.low = LOW_1;
	fdf->scheme.fine = FINE_1;
	fdf->scheme.norm = NOR_1;
	fdf->scheme.high = HIGH_1;
	fdf->lines = 1;
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;
	int	i;

	i = 1;
	fdf =(t_fdf*)malloc(sizeof(t_fdf));
	set_params(fdf);
	if (argc == 2)
		if (ft_read_map(fdf, argv[1]) < 0)
		{
			free(fdf);
			ft_putstr("error!\n");
			return (0);
		}
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
	print_menu(fdf);
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	clean_fdf(&fdf);
	return (0);
}

// compile gcc -Wall -Wextra -Werror main.c draw.c read_map.c LIB/*.c get_next_line/get_next_line.c minilibx_macos/libmlx.a -framework OpenGL -framework AppKit