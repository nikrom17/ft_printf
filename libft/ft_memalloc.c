/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:39:01 by nroman            #+#    #+#             */
/*   Updated: 2018/03/11 23:51:38 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)malloc(sizeof(mem) * size);
	if (mem)
	{
		i = 0;
		while (i < size)
			mem[i++] = 0;
		return ((void *)mem);
	}
	return (NULL);
}
