/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:48:33 by nroman            #+#    #+#             */
/*   Updated: 2018/06/02 08:29:20 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void) 
{
	//int		num = 11;
	char	*string = "did it on `em";

	ft_printf("5\n");
	printf("5\nn");
	ft_printf("MEEE - String value: %s\n",string);
	printf("THEM - String value: %s\n",string);

	//printf("%s\n", ft_itoa_base(num, 2));
}
