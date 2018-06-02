/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:15:11 by nroman            #+#    #+#             */
/*   Updated: 2018/02/28 11:04:18 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	if (i < size)
	{
		while (src[j] != '\0' && j < (size - i - 1))
		{
			dest[j + i] = src[j];
			j++;
		}
	}
	if (size != 0 || i < size)
		dest[i + j] = '\0';
	if (i > size)
		return (size + ft_strlen(src));
	else
		return (i + ft_strlen(src));
}
