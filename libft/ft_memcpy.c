/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:11:57 by nroman            #+#    #+#             */
/*   Updated: 2018/02/27 19:20:36 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest,
		const void *src, size_t len)
{
	char			*d;
	const char		*s;

	if (len)
	{
		d = (char *)dest;
		s = src;
		while (len--)
			*d++ = *s++;
	}
	return (dest);
}
