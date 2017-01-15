/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 04:19:16 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/15 05:32:05 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static void	ft_putcharerror(char c)
{
	write(2, &c, 1);
}

void		ft_puterror(char const *s)
{
	int a;

	a = 0;
	while (s[a] != '\0')
	{
		ft_putcharerror(s[a]);
		a++;
	}
}
