/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:48:33 by nroman            #+#    #+#             */
/*   Updated: 2018/06/04 21:37:55 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void) 
{
	//int		num = 42;
	char	*str = "did";
	//char	*str1 = "it";
	//char	*str2 = "on `em";

	ft_printf("MEEE: %.1s\n", str);
	printf("THEM: %.1s\n", str);
	//ft_printf("MEEE - String value: %c %s %s\n",str[0], str1, str2);
	//printf("THEM - String value: %c %s %s\n",str[0], str1, str2);

//	printf("%s\n", ft_itoa_base(num, 10));
}
