/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:48:33 by nroman            #+#    #+#             */
/*   Updated: 2018/06/04 22:37:23 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void) 
{
//	int		num = 42;
	//wchar_t		c = 128;
	//char	*str = "did";
	//char	*str1 = "it";
	//char	*str2 = "on `em";

	ft_printf("MEEE: %4.15d", 42);
	printf("THEM: %4.15d", 42);
	//ft_printf("MEEE - String value: %c %s %s\n",str[0], str1, str2);
	//printf("THEM - String value: %c %s %s\n",str[0], str1, str2);

//	printf("%s\n", ft_itoa_base(num, 10));
}
