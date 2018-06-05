/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:09:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/04 20:11:27 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "libft.h"

char	*ft_itoa_base(long long int nb, int base)
{
	long long int		i;
	int					len;
	char				*res;
	int					temp;
	int					flag;

	i = 0;
	flag = 0;
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
		flag =1;
		nb = nb * -1;
		res[len - 1] = '-';
	}
	while (nb > 0)
	{
		temp = nb % base;
		if (temp > 9)
			res[i++] = 'a' + (temp - 10);
		else
			res[i++] = temp + '0';
		nb /= base;
	}
	if (flag)
		res[++i] = 0;
	else
		res[i] = 0;
	return (ft_strrev(res));
}
