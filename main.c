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

#include <mlx.h>

int f(int key, void *param)
{
	//mlx_destroy_window(mlx_ptr, win);
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win;

	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 1000, 500, "FDF");
	mlx_string_put(mlx_ptr, win, 500, 250, 0xFFFFFF, "HELLO WORLD!");
	mlx_key_hook(win, f, (void*)0);
	mlx_loop(mlx_ptr);
	return (0);
}

// compile cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit