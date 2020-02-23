/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:48:35 by rlintill          #+#    #+#             */
/*   Updated: 2019/09/07 14:26:33 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str[0] == '\0' && substr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (substr[j] != '\0' && str[i + j] == substr[j])
			j++;
		if (substr[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}