/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:40:30 by nroman            #+#    #+#             */
/*   Updated: 2018/02/25 20:07:32 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

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
			new[i] = f((char)s[i]);
		new[i] = 0;
		return (new);
	}
	return (new);
}
