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

int deal_key(int key, void *data)
{
	ft_putnbr(key);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;
	int	i;

	i = 1;
	fdf =(t_fdf*)malloc(sizeof(t_fdf));
	fdf->width = 0;
	fdf->height = 0;
	fdf->zoom = 1;
	if (argc == 2)
		if (ft_read_map(fdf, argv[1]) < 0)
		{
			free(fdf);
			ft_putstr("error!\n");
			return (0);
		}
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
	//bresenham(fdf, 1, 1, 1, 2);
	//bresenham(fdf, 1, 1, 2, 1);
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, NULL);
	mlx_loop(fdf->mlx_ptr);
	free(fdf);
	return (0);
}

// compile cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit