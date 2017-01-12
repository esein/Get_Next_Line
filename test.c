/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:41:42 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/12 01:53:45 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int	read_and_add(const int fd, t_gnl *gnl);

int	main(void)
{
	int fd;
	fd = open("asd", O_RDONLY);
	t_gnl gnl[MULTI_FD];
	gnl[fd].str_new = malloc(1);
	gnl[fd].str_new[0] = '\0';
	read_and_add(fd, (&(gnl[fd])));
//	ft_putstr(gnl[fd].str_new);
	close(fd);
//	ft_putstr(gnl[fd].str_old);
	return(0);
}
