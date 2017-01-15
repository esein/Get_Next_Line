/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:17:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/15 09:27:34 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/Includes/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		old_to_new(t_gnl *gnl)
{
	int		i;
	int		i2;
	char	*tmp;

	i = 0;
	i2 = 0;
	gnl->str_new = malloc(sizeof(char) *
			(1 + ft_strlentil(gnl->str_old, '\n', 0)));
	while (gnl->str_old[i])
	{
		if ((gnl->ret = 1) && gnl->str_old[i] == '\n')
		{
			gnl->str_new[i++] = '\0';
			tmp = ft_strsub(gnl->str_old, i, ft_strlen(&gnl->str_old[i]));
			free(gnl->str_old);
			gnl->str_old = tmp;
			return (1);
		}
		gnl->str_new[i2] = gnl->str_old[i];
		i++;
		i2++;
	}
	gnl->str_new[i] = '\0';
	free(gnl->str_old);
	return (0);
}

int		read_and_add(const int fd, t_gnl *gnl)
{
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		gnl->ret = 1;
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
			i++;
		gnl->str_new = ft_realloc(gnl->str_new, ft_strlen(gnl->str_new) + i + 1,
				ft_strlen(gnl->str_new) + 1);
		ft_strncat(gnl->str_new, buf, i);
		if (buf[i] == '\n')
		{
			i++;
			gnl->str_old = malloc(sizeof(char) * (ft_strlen(&buf[i]) + 1));
			ft_strcpy(gnl->str_old, &buf[i]);
			return (1);
		}
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl gnl[MULTI_FD];

	if (fd < 0 || line == NULL || fd > MULTI_FD)
		return (-1);
	gnl[fd].ret = 0;
	gnl[fd].str_new = (char *)malloc(sizeof(char) * 1);
	gnl[fd].str_new[0] = '\0';
	if (gnl[fd].notfirst == 1)
	{
		if (old_to_new(&(gnl[fd])))
		{
			*line = gnl[fd].str_new;
			return (1);
		}
	}
	gnl[fd].notfirst = read_and_add(fd, &(gnl[fd]));
	*line = gnl[fd].str_new;
	if (gnl[fd].notfirst == -1)
		return (-1);
	return (gnl[fd].ret);
}
