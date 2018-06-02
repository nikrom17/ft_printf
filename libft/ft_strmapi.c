/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:40:30 by nroman            #+#    #+#             */
/*   Updated: 2018/02/25 20:07:43 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	new = (char *)malloc(sizeof(char) * i + 1);
	if (new)
	{
		i = -1;
		while (s[++i])
			new[i] = f(i, (char)s[i]);
		new[i] = 0;
		return (new);
	}
	return (new);
}
