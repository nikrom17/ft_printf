/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:54:08 by nroman            #+#    #+#             */
/*   Updated: 2018/02/25 19:55:10 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(nb);
	res = (char *)malloc(sizeof(char) + len);
	if (!res)
		return (NULL);
	else if (nb < 0)
	{
		nb = nb * -1;
		res[len - 1] = '-';
	}
	while (nb > 0)
	{
		res[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	res[len] = 0;
	return (ft_strrev(res));
}
