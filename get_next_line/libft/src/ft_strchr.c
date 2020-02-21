/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:35:12 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 15:30:28 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int symb)
{
	char		*buf;
	unsigned	i;

	i = 0;
	buf = (char*)str;
	while (i <= ft_strlen(str))
	{
		if (buf[i] == (unsigned char)symb)
			return ((void*)&buf[i]);
		i++;
	}
	return (NULL);
}
