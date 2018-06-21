/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:25:07 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 09:49:13 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size, char c)
{
	size_t	i;
	char	*new;

	new = (char *)malloc(sizeof(char) * size + 1);
	if (new)
	{
		i = 0;
		while (i < size)
			new[i++] = c;
		new[i] = 0;
		return (new);
	}
	return (NULL);
}
