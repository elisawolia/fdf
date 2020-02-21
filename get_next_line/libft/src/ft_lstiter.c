/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:57:58 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 15:14:28 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst == NULL || f == NULL)
		return ;
	if (lst->next)
		ft_lstiter(lst->next, f);
	(*f)(lst);
}
