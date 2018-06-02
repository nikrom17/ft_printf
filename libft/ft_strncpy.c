/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:57:54 by nroman            #+#    #+#             */
/*   Updated: 2018/02/27 21:21:16 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = -1;
	if (n)
	{
		while (++i < n && src[i])
			dest[i] = src[i];
		while (i < n)
			dest[i++] = 0;
	}
	return (dest);
}
