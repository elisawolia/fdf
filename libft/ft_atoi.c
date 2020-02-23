/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 09:23:40 by rlintill          #+#    #+#             */
/*   Updated: 2019/09/18 11:56:20 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == '\n' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f' || c == ' ');
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					negative;
	int					i;

	i = 0;
	negative = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (i > 19 || result >= 9223372036854775807)
		return (negative == 1 ? -1 : 0);
	return (result * negative);
}