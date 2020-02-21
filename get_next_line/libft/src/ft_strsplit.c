/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:49:28 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 15:22:07 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_l(char *s, char c, int j)
{
	unsigned	i;

	i = 0;
	while (s[j + i] != c && s[j + i] != '\0')
		i++;
	i++;
	return (i);
}

static	int		ft_cwords(char *s, char c)
{
	unsigned	i;
	size_t		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	w++;
	return (w);
}

static	char	*ft_putw(const char *s, char *dst, char c, int i)
{
	unsigned	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		dst[j] = s[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		w;
	char		**buf;
	unsigned	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(buf = (char **)malloc(sizeof(char*) * ft_cwords((char*)s, c))))
		return (NULL);
	w = 0;
	while (s[i] != '\0')
	{
		if (USLOVIE1 || USLOVIE2)
		{
			while (s[i] == c)
				i++;
			if (!(buf[w] = (char*)malloc(sizeof(char) * ft_l((char*)s, c, i))))
				return (NULL);
			buf[w] = ft_putw(s, buf[w], c, i);
			w++;
		}
		i++;
	}
	buf[w] = NULL;
	return (buf);
}
