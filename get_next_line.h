/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:08:30 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/13 08:16:40 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9999
# define MULTI_FD 100

typedef struct	s_gnl
{
	char	*str_new;
	char	*str_old;
	int		check;
	int		notfirst;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
