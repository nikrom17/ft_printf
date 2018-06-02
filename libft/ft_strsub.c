/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:28 by nroman            #+#    #+#             */
/*   Updated: 2018/02/24 10:04:25 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;

	if (s)
	{
		dst = (char *)malloc(sizeof(char) * (len + 1));
		if (dst)
		{
			i = start;
			j = 0;
			while (i < (start + len))
			{
				dst[j++] = s[i++];
			}
			dst[j] = 0;
			return (dst);
		}
	}
	return (NULL);
}
