/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:19:31 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/21 10:19:33 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include "LIB/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_fdf
{
	int		height;
	int		width;
	int		**map;
	int		zoom;
	int		color;


	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

int		ft_read_map(t_fdf *fdf, char *file);
int		get_width(char *line);
void	bresenham(t_fdf *fdf, float x, float y, float x1, float y1);
void	draw(t_fdf *fdf);


#endif