/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:51:21 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/15 05:06:01 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		count;

	count = 0;
	while (src[count] != 0)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = src[count];
	return (dest);
}
