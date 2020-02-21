/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:37:13 by rlintill          #+#    #+#             */
/*   Updated: 2019/10/12 15:49:55 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line);

#endif
