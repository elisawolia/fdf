/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:43:39 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 15:15:26 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*buf;
	unsigned		i;

	i = 0;
	buf = (unsigned char*)malloc(size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, size);
	return ((void*)buf);
}
