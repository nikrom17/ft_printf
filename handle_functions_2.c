/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:39:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 09:35:29 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_hash_helper(char *input_string, int i, t_struct *flags)
{
	if (flags->str_args)
	{
		if (flags->str_args[0] != '0')
		{
			if (flags->width > 0 && flags->zero == '1')
				flags->hash = ft_strdup("0");
			else
				flags->str_args = ft_strjoin("0", flags->str_args);
		}
	}
}

void	handle_hash(char *input_string, int i, t_struct *flags)
{
	if (flags->str_args)
	{
		if (flags->type == 'x')
		{
			if (flags->str_args[0] != '0' || flags->type == 'p')
			{
				if (flags->width > 0 && flags->zero == '1')
					flags->hash = ft_strdup("0x");
				else
					flags->str_args = ft_strjoin("0x", flags->str_args);
			}
		}
		else if (flags->type == 'X')
		{
			if (flags->str_args[0] != '0')
			{
				if (flags->width > 0 && flags->zero == '1')
					flags->hash = ft_strdup("0X");
				else
					flags->str_args = ft_strjoin("0X", flags->str_args);
			}
		}
		else
			handle_hash_helper(input_string, i, flags);
	}
}

void	handle_h(char *input_string, int i, t_struct *flags)
{
	if (flags->size_modifier == 'h')
	{
		flags->size_modifier = '0';
		if (flags->type == 'd' || flags->type == 'i')
			flags->str_args = ft_itoa_base((short)
				va_arg(flags->args, int), flags->base);
		else
			flags->str_args = ft_uitoa_base((unsigned short)
				va_arg(flags->args, int), flags->base);
	}
}

void	handle_hh(char *input_string, int i, t_struct *flags)
{
	if (flags->size_modifier == 'H')
	{
		flags->size_modifier = '0';
		if (flags->type == 'd' || flags->type == 'i')
			flags->str_args = ft_itoa_base((signed char)
				va_arg(flags->args, int), flags->base);
		else
			flags->str_args = ft_uitoa_base((unsigned char)
				va_arg(flags->args, int), flags->base);
	}
}

void	handle_l(char *input_string, int i, t_struct *flags)
{
	size_t		temp;

	if (flags->size_modifier == 'l' && flags->type != 's')
	{
		flags->size_modifier = '0';
		if (flags->type == 'd' || flags->type == 'i' || flags->type == 'D')
		{
			temp = va_arg(flags->args, long);
			flags->str_args = ft_itoa_base(temp, flags->base);
		}
		else
		{
			flags->size_modifier = '0';
			temp = va_arg(flags->args, unsigned long);
			flags->str_args = ft_uitoa_base(temp, flags->base);
		}
	}
}
