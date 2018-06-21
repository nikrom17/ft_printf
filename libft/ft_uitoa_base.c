/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:09:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 08:50:18 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned long long int nb, int base)
{
	long long int		i;
	char				*res;
	int					temp;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) + 17);
	if (!res)
		return (NULL);
	while (nb > 0)
	{
		temp = nb % base;
		if (temp > 9)
			res[i++] = 'a' + (temp - 10);
		else
			res[i++] = temp + '0';
		nb /= base;
	}
	res[i] = 0;
	return (ft_strrev(res));
}
