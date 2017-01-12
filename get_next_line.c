/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:17:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/12 05:15:31 by gcadiou          ###   ########.fr       */
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
			return (1);
		}
	}
	gnl->str_new[i] = '\0';
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
		gnl->str_new = ft_realloc(gnl->str_new, ft_strlen(gnl->str_new) + i + 1,
				ft_strlen(gnl->str_new) + 1);
		ft_strncat(gnl->str_new, buf, i);
		if (buf[i] == '\n')
		{
			gnl->str_old = malloc(sizeof(char) * (strlen(&buf[i]) + 1));
			ft_strcpy(gnl->str_old, &buf[i]);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl gnl[MULTI_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	gnl[fd].str_new = (char *)malloc(sizeof(char) * 1);
	gnl[fd].str_new[0] = '\0';
	if (gnl[fd].notfirst != 1)
		gnl[fd].notfirst = 1;
	else
		if (old_to_new(&(gnl[fd])))
		{
			*line = gnl[fd].str_new;
			return (1);
		}
	gnl[fd].str_new = (char *)malloc(sizeof(char) * 1);
	gnl[fd].str_new[0] = 'a';
	ft_putchar(gnl[fd].str_new[0]);
	read_and_add(fd, &(gnl[fd]));
	return (1);
}
/*
int main()
{
	int fd;
	char *line;

	fd = open("asd",O_RDONLY);
	get_next_line(fd, &line);
//	get_next_line(fd, &line);
	ft_putstr(line);
}*/
