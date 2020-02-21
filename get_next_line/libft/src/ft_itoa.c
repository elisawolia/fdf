/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:22:04 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 14:54:32 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*nbr(char *buf, int k, int f, int n)
{
	buf[k + 1] = '\0';
	while ((k > 0 && f == 1) || (f == 0 && k > 1))
	{
		buf[k] = '0' + n % 10;
		k--;
		n = n / 10;
	}
	buf[k] = '0' + n;
	if (f == 0)
		buf[0] = '-';
	return (buf);
}

static	int		ft_itsymb(int n)
{
	int		k;

	k = 0;
	if (n <= 0)
		k++;
	while (n != 0)
	{
		n = n / 10;
		k++;
	}
	return (k);
}

char			*ft_itoa(int n)
{
	int		k;
	char	*buf;
	int		f;
	char	*buf_min;

	k = ft_itsymb(n) - 1;
	f = 1;
	if (n == -2147483648)
	{
		buf_min = (char*)malloc(sizeof(char) * 12);
		ft_strcpy(buf_min, "-2147483648");
		return (buf_min);
	}
	if (n < 0)
	{
		f = 0;
		n *= -1;
	}
	buf = (char*)malloc(sizeof(char) * (k + 2));
	if (buf == NULL)
		return (NULL);
	buf = nbr(buf, k, f, n);
	return (buf);
}
