/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:53:32 by gcadiou           #+#    #+#             */
/*   Updated: 2017/01/12 03:42:23 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "Libft.h"

void	*test_rea(char *ptr, size_t size_to_malloc, size_t size_actual)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(size_to_malloc);
	ft_memmove(new, ptr, size_actual);
	free(ptr);
	return (new);
}
