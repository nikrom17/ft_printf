/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:01:58 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 16:38:07 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = -1;
	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		dst = (char *)malloc((sizeof(char) * i + j) + 1);
		if (dst)
		{
			i = -1;
			while (s1[++i])
				dst[i] = s1[i];
			j = -1;
			while (s2[++j])
				dst[i + j] = s2[j];
			dst[i + j] = 0;
			return (dst);
		}
	}
	return (NULL);
}
