/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:49:05 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/23 17:15:12 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float a)
{
	return ((a >= 0) ? a : -a);
}

t_dot	new_dot(int x, int y)
{
	t_dot	dot;

	dot.x = x;
	dot.y = y;
	return (dot);
}

double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

int		hex_to_dec(char *hex)
{
	int		len;
	int		res;
	int		i;
	char	temp;

	len = ft_strlen(hex);
	res = 0;
	i = 0;
	while (i < len)
	{
		temp = hex[i];
		if (ft_isdigit(hex[i]))
			temp -= '0';
		else if ((temp >= 'A' && temp <= 'F') || (temp >= 'a' && temp <= 'f'))
			temp = ft_toupper(temp) - 'A' + 10;
		res += temp * ft_pow(16, ((len - i) - 1));
		i++;
	}
	return (res);
}

void	ft_clear(char **buf, int w)
{
	while (w >= 0)
	{
		ft_strdel(&buf[w]);
		w--;
	}
	free(*buf);
}
