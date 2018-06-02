/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:16:05 by nroman            #+#    #+#             */
/*   Updated: 2018/02/22 08:45:25 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*cpy;

	cpy = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		if (cpy[i] == (unsigned char)c)
			return (cpy + i);
		i++;
	}
	return (0);
}
