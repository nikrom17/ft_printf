/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:39:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 21:05:44 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_hex(char *input_string, int i, t_struct *flags)
{
	int		j;

	j = -1;
	if (input_string[i] == 'X')
	{
		while (flags->str_args[++j])
			flags->str_args[j] = ft_toupper(flags->str_args[j]);
	}
	flags->chars_printed += ft_strlen(flags->str_args);
	ft_putstr(flags->str_args);
}

void	handle_character(char *input_string, int i, t_struct *flags)
{
	int		j;
	int		len;

	if (flags->str_args)
	{
		if (flags->minus == '1')
			ft_putchar(flags->c);
		len = ft_strlen(flags->str_args);
		len--;
		j = -1;
		flags->chars_printed += (len + 1);
		while (++j < len)
			ft_putchar(flags->str_args[j]);
		if (flags->minus == '0')
			ft_putchar(flags->c);
	}
	else
	{
		flags->chars_printed += 1;
		ft_putchar(flags->c);
	}
}

void	handle_wcharacter(char *input_string, int i, t_struct *flags)
{
	flags->chars_printed += 1;
	ft_putchar(flags->c);
}

void	pass(char *input_string, int i, t_struct *flags)
{
}

