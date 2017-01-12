/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:53:32 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/12 04:30:56 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*test_rea(char *ptr, size_t size_to_malloc, size_t size_actual)
{
	char	*new;
	size_t	i;

	i = 0;
	if(ptr == NULL)
		return (0);
	new = (char *)malloc(sizeof(char) * size_to_malloc);
	memmove(new, ptr, size_actual);
	ft_putendl(new);
	free(ptr);
	return (new);
}
