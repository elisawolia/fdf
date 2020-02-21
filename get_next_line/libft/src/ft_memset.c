/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:11:24 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 15:16:34 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int s, size_t len)
{
	unsigned		i;
	unsigned char	*buf;

	buf = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		buf[i] = (unsigned char)s;
		i++;
	}
	return (buf);
}
