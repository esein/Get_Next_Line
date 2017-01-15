/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:41:42 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/15 06:59:34 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Libft/Includes/libft.h"
#include "get_next_line.h"

int	read_and_add(const int fd, t_gnl *gnl);

int	main(void)
{
	int fd;
	int fd2;
	int x = 0;
	char *line;
	t_gnl gnl[MULTI_FD];
	fd = open("lol", O_RDONLY);
	gnl[fd].str_new = malloc(1);
	gnl[fd].str_new[0] = '\0';
	gnl[fd].str_old = malloc(1);
	gnl[fd].str_old[0] = '\0';
	while (get_next_line(fd, &line))
		ft_putendl(line);
/*	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(line);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(line);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(line);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(line);*/
	//	while (get_next_line(fd2, &line))
//		ft_putstr(line);*/
/*	get_next_line(fd, &line);
	ft_putnbr(strcmp(line,"aaa"));
	get_next_line(fd, &line);
	ft_putnbr(strcmp(line,"bbb"));
	get_next_line(fd, &line);
	ft_putnbr(strcmp(line,"ccc"));
	get_next_line(fd, &line);
	ft_putnbr(strcmp(line,"ddd"));*/
	close(fd);
	close(fd2);
	return(0);
}
