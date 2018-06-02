/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:09:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/02 08:29:17 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "libft.h"

char	*ft_itoa_base(long long int nb, int base)
{
	long long int		i;
	int					len;
	char				*res;
	int					temp;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(nb);
	res = (char *)malloc(sizeof(char) + 17);
	if (!res)
		return (NULL);
	else if (nb < 0)
	{
		nb = nb * -1;
		res[len - 1] = '-';
	}
	while (nb > 0)
	{
		temp = nb % base;
		if (temp > base - 1)
			res[i++] = 'a' + (temp - 10);
		else
			res[i++] = temp + '0';
		nb /= base;
	}
	res[i] = 0;
	return (ft_strrev(res));
}
