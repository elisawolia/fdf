/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:09:48 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/23 18:13:42 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *fdf)
{
	char *menu;

	menu = "To move picture: up, down, left, right";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 10, 0xffffff, menu);
	menu = "To zoom in/out: +/-";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 30, 0xffffff, menu);
	menu = "To change height: z/x";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 50, 0xffffff, menu);
	menu = "3D mode on/off: q/w";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 70, 0xffffff, menu);
	menu = "To change color scheme: 1/2/3";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 90, 0xffffff, menu);
	menu = "Dots/lines mode: l/k";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 110, 0xffffff, menu);
	menu = "To quit: ESC";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 130, 0xffffff, menu);
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

void	clean_fdf(t_fdf **fdf)
{
	int		i;

	i = 0;
	while ((*fdf)->map[i])
	{
		free((*fdf)->map[i]);
		i++;
	}
	free((*fdf)->map);
	free(*fdf);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;

	i = 1;
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
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
