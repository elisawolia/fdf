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

int		get_width(char *line)
{
	char **nums;
	int	i;
	int	j;

	j = 0;
	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		j = 0;
		while (nums[i][j])
		{
/*			if (!(ft_isdigit(nums[i][j]) && nums[i][j] != '-')
			{
				return (-1);
			}*/
			j++;
		}
		i++;
	}
	// needs to be cleaned
	return (i);
}

void print_map(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_putnbr(fdf->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_fill(t_fdf *fdf, char *line, int i)
{
	char **nums;
	int j;

	j = 0;
	if (!(nums = ft_strsplit(line, ' ')))
		return ;
	while (nums[j])
	{
		fdf->map[i][j] = ft_atoi(nums[j]);
		free(nums[j]);
		j++;
	}
	fdf->map[i][j] = '\0';
	free (nums);
}

int	ft_fill_map(t_fdf *fdf, char *file)
{
	int	fd;
	char *line;
	int i;
	int	j;

	i = 0;
	j = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	if (!(fdf->map = (int**)malloc(sizeof(int*) * (fdf->height + 1))))
		return (-1);
	while (i < fdf->height)
	{
		fdf->map[i] = (int*)malloc(sizeof(int) * (fdf->width + 1));
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_fill(fdf, line, i);
		free(line);
		i++;
	}
	fdf->map[i] = NULL;
	close(fd);
	return (1);
}

int	ft_read_map(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		fdf->height++;
		if (fdf->width == 0)
		{
			fdf->width = get_width(line);
		}
		else if (fdf->width != get_width(line))
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