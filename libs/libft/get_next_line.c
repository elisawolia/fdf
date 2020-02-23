/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahandsom <ahandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:39:16 by rlintill          #+#    #+#             */
/*   Updated: 2020/02/23 13:42:47 by ahandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_list(t_list *lst, int fd, t_list **nw)
{
	if (lst == NULL)
	{
		*nw = NULL;
		return (0);
	}
	if ((int)lst->content_size == fd)
	{
		*nw = lst;
		return (1);
	}
	if (lst->next)
		return (check_list(lst->next, fd, nw));
	*nw = NULL;
	return (0);
}

void	ft_delelem(t_list **list, t_list **elem)
{
	t_list	*buf;

	if (!list || !elem || !*list || !*elem)
		return ;
	buf = *list;
	if (*elem == *list)
	{
		free((*list)->content);
		buf = (*list)->next;
		free(*list);
		*list = buf;
	}
	else if (buf->next)
	{
		while (buf->next != *elem)
			buf = buf->next;
		buf->next = (*elem)->next;
		ft_strdel((char**)&(*elem)->content);
		free(*elem);
		*list = buf;
	}
	*elem = NULL;
}

int		cop(char **line, t_list **now)
{
	int		i;
	char	*temp;
	int		strsize;

	i = 0;
	temp = (char*)(*now)->content;
	while (temp[i] != '\n' && temp[i])
		i++;
	strsize = (temp[i]) ? i : (int)ft_strlen((*now)->content);
	if (!(*line = ft_strnew((sizeof(char) * strsize))))
		return (0);
	ft_memcpy(*line, (*now)->content, strsize);
	if (temp[i] && temp[i + 1])
	{
		if (!(temp = ft_strdup(temp + i + 1)))
			return (0);
		ft_strdel((char**)&(*now)->content);
		(*now)->content = temp;
	}
	else
	{
		free(temp);
		(*now)->content = NULL;
	}
	return (1);
}

void	read_gnl(int *i, int fd, t_list **elem)
{
	char	*temp;
	char	*buf;

	if (!(buf = ft_strnew(sizeof(char) * BUFF_SIZE + 1)))
		return ;
	while ((*i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*i] = '\0';
		if ((*elem)->content)
		{
			temp = (*elem)->content;
			if (!((*elem)->content = ft_strjoin((*elem)->content, buf)))
				return ;
			if (temp)
				free(temp);
		}
		else if (!((*elem)->content = ft_strdup(buf)))
			return ;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	ft_strdel(&buf);
}

int		get_next_line(const	int fd, char **line)
{
	static	t_list	*list;
	t_list			*new;
	int				i;

	i = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	*line = NULL;
	if (!check_list(list, fd, &new))
	{
		new = ft_lstnew(NULL, 0);
		new->content_size = fd;
		ft_lstadd(&list, new);
	}
	read_gnl(&i, fd, &new);
	if (i < 0)
		return (-1);
	else if (!new->content && i == 0)
	{
		ft_delelem(&list, &new);
		return (0);
	}
	if (!(cop(line, &new)))
		return (-1);
	return (1);
}
