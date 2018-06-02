/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:40:29 by nroman            #+#    #+#             */
/*   Updated: 2018/02/27 19:16:37 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cpy;

	cpy = (unsigned char *)b;
	if (len)
	{
		i = 0;
		while (i < len)
			cpy[i++] = (unsigned char)c;
	}
	return (b);
}
