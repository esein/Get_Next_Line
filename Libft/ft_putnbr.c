/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:31:22 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/15 05:32:40 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int	lboucles(long nb)
{
	char	b;

	while (nb > 0)
	{
		b = (char)(nb % 10) + '0';
		nb = lboucles(nb / 10);
		ft_putchar(b);
	}
	return (0);
}

void		ft_putnbr(int nb)
{
	long	lnb;

	if (nb < 0)
	{
		lnb = nb;
		ft_putchar('-');
		lnb = lnb * -1;
		lboucles(lnb);
	}
	else if (nb == 0)
		ft_putchar('0');
	else
		lboucles(nb);
}
