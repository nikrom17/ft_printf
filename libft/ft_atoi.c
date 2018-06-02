/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:08:50 by nroman            #+#    #+#             */
/*   Updated: 2018/02/27 20:28:26 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_return(unsigned long long num, int neg)
{
	if (num > 9223372036854775807)
		return (neg == -1 ? 0 : -1);
	else
		return (num * neg);
}

int				ft_atoi(const char *str)
{
	int					i;
	long long int		num;
	int					j;
	long long int		sign;

	i = 0;
	num = 0;
	j = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	j = i;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == 0 || (i == 1 && j == 1))
		return (0);
	i--;
	while (j <= i)
		num = (num * 10) + (long long int)(str[j++] - '0');
	return (ft_check_return(num, sign));
}
