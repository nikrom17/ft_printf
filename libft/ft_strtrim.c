/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:53:37 by nroman            #+#    #+#             */
/*   Updated: 2018/05/30 15:10:01 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		size;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s) - 1;
	while (ft_isnst(s[size]) && size > 0)
		size--;
	if (size == 0)
		return (ft_strnew(0, 0));
	i = 0;
	while (ft_isnst(s[i++]))
		size--;
	if ((dst = (char *)malloc(sizeof(char) * (size + 2))))
	{
		j = 0;
		while (j < size + 1)
			dst[j++] = s[i++ - 1];
		dst[j] = 0;
		return (dst);
	}
	return (NULL);
}
