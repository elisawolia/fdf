/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:32:32 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/21 10:32:34 by rlintill         ###   ########.fr       */
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

int		get_width(char *line)
{
	char	**nums;
	int		i;
	int		j;

	j = 0;
	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		j = 0;
		while (nums[i][j++])
		{
			if (!ft_isdigit(nums[i][0]) &&
				nums[i][0] != '-' && nums[i][0] != '+')
			{
				ft_clear(nums, i);
				free(nums);
				return (-1);
			}
		}
		i++;
	}
	ft_clear(nums, i);
	free(nums);
	return (i);
}

int	ft_fill(t_fdf *fdf, char *line, int i)
{
	char	**nums;
	int		j;

	j = 0;
	if (!(nums = ft_strsplit(line, ' ')))
		return (-1);
	while (nums[j])
	{
		if ((nums[j][0] >= '0' && nums[j][0] <= '9')
			|| nums[j][0] == '-' || nums[j][0] == '+')
			fdf->map[i][j].data = ft_atoi(nums[j]);
		else
		{
			ft_clear(nums, j);
			return (-1);
		}
		fdf->map[i][j].color = read_color(nums[j], fdf->map[i][j].data,
			fdf, &(fdf->map[i][j].col_def));
		free(nums[j]);
		j++;
	}
	free(nums);
	return (0);
}

int	map(t_fdf *fdf, char *file)
{
	int	fd;
	int	i;

	i = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(fdf->map = (t_point**)malloc(sizeof(t_point*) * (fdf->height + 1))))
	{
		close(fd);
		return (0);
	}
	while (i < fdf->height)
	{
		if (!(fdf->map[i] =
			(t_point*)malloc(sizeof(t_point) * (fdf->width + 1))))
		{
			close (fd);
			clean_fdf(&fdf);
			return (0);
		}
		i++;
	}
	return (fd);
}

int	ft_fill_map(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(fd = map(fdf, file)))
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_fill(fdf, line, i) == -1)
		{
			free(line);
			clean_fdf(&fdf);
			close(fd);
			return (-1);
		}
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

int	ft_read_map(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;
	int		width;

	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		fdf->height++;
		if (!(width = get_width(line)))
		{
			ft_putstr("Im out\n");
			free(line);
			return (-1);
		}
		if (fdf->width == 0)
			fdf->width = width;
		else if (fdf->width != width)
		{
			ft_putstr("Im out\n");
			free(line);
			return (-1);
		}
		free(line);
	}
	close(fd);
	return (ft_fill_map(fdf, file));
}
