/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:39:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 10:13:49 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_ll(char *input_string, int i, t_struct *flags)
{
	if (flags->size_modifier == 'L')
	{
		flags->size_modifier = '0';
		if (flags->type == 'd' || flags->type == 'i')
			flags->str_args = ft_itoa_base(
				va_arg(flags->args, long long), flags->base);
		else
			flags->str_args = ft_uitoa_base(
				va_arg(flags->args, unsigned long long), flags->base);
	}
}

void	handle_j(char *input_string, int i, t_struct *flags)
{/*
	if (flags->size_modifier == 'j')
	{
		flags->size_modifier = 'J';
		if (flags->type == 'd' || flags->type == 'i')
			flags->str_args = ft_itoa_base(
				va_arg(flags->args, intmax_t), flags->base);
		else
			flags->str_args = ft_uitoa_base(
				va_arg(flags->args, uintmax_t), flags->base);
	} */
}

void	handle_z(char *input_string, int i, t_struct *flags)
{
	if (flags->size_modifier == 'z')
	{
		flags->size_modifier = 'Z';
		if (flags->type == 'd' || flags->type == 'i')
			flags->str_args = ft_itoa_base(
				va_arg(flags->args, size_t), flags->base);
		else
			flags->str_args = ft_uitoa_base(
				va_arg(flags->args, size_t), flags->base);
	}
}

void	handle_unsigned(char *input_string, int i, t_struct *flags)
{
	flags->chars_printed += ft_strlen(flags->str_args);
	ft_putstr(flags->str_args);
}

void	handle_octal(char *input_string, int i, t_struct *flags)
{
	int		j;

	j = -1;
	if (input_string[i] == 'O')
	{
		while (flags->str_args[++j])
			flags->str_args[j] = ft_toupper(flags->str_args[j]);
	}
	flags->chars_printed += ft_strlen(flags->str_args);
	ft_putstr(flags->str_args);
}
