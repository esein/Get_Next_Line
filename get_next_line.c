/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:17:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/13 08:27:47 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		old_to_new(t_gnl *gnl)
{
	int		i;
	char	*tmp;

	i = 0;
	gnl->str_new = malloc(sizeof(char) *
			(1 + ft_strlentil(gnl->str_old, '\n', i)));
	while (gnl->str_old[i])
	{
		gnl->str_new[i] = gnl->str_old[i];
		i++;
		if (gnl->str_old[i] == '\n')
		{
			gnl->str_new[i] = '\0';
			i++;
			tmp = ft_strsub(gnl->str_old, i, ft_strlentil(gnl->str_old, '\n',
						i));
			free(gnl->str_old);
			gnl->str_old = tmp;
			return (1);
		}
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

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
			i++;
		if (i > 0)
			gnl->check = 1;
		gnl->str_new = ft_realloc(gnl->str_new, ft_strlen(gnl->str_new) + i + 1,
				ft_strlen(gnl->str_new) + 1);
		ft_strncat(gnl->str_new, buf, i);
		if (buf[i] == '\n')
		{
			while (buf[i] == '\n')
				i++;
			if (buf[i] || gnl->check == 1)
			{
				gnl->check = 1;
				gnl->str_old = malloc(sizeof(char) * (ft_strlen(&buf[i]) + 1));
				ft_strcpy(gnl->str_old, &buf[i]);
				return (1);
			}
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl gnl[MULTI_FD];

//	*line = (char *)malloc(sizeof(char) * 1);
//	*line[0] = '\0';
	gnl[fd].check = 0;
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
	return (gnl[fd].check);
//	return ((*line[0] == '\0') ? 0 : 1);
}
