/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:30:41 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/25 08:37:06 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	DECLAR;
	is = -1;
	in = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (0);
	while (++is < lens1)
	{
		new[in] = s1[is];
		in++;
	}
	is = 0;
	while (is < lens2)
	{
		new[in] = s2[is];
		is++;
		in++;
	}
	new[in] = '\0';
	return (new);
}
