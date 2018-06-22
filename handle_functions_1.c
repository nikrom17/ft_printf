/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:39:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 09:35:21 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_precision_helper(char *input_string, int i, t_struct *flags)
{
	char	*str_cpy;
	int		len;
	char	*temp;

	len = ft_strlen(flags->str_args);
	if (flags->plus == '2' || flags->neg == '1')
		len--;
	if (flags->precision > len)
	{
		str_cpy = ft_strnew(flags->precision - len, '0');
		if (flags->plus == '2' || flags->neg == '1')
		{
			flags->str_args[0] = '0';
			if (flags->neg == '1')
				str_cpy[0] = '-';
			else
				str_cpy[0] = '+';
		}
		if (!ft_strcmp(flags->hash, " "))
			str_cpy = ft_strjoin(flags->hash, str_cpy);
		temp = ft_strjoin(str_cpy, flags->str_args);
		free(flags->str_args);
		flags->str_args = temp;
	}
}

void	handle_precision(char *input_string, int i, t_struct *flags)
{
	char	*str_cpy;

	if (flags->type == 's')
	{
		if (flags->precision < ft_strlen(flags->str_args))
		{
			str_cpy = ft_strdup(flags->str_args);
			str_cpy[flags->precision] = 0;
			flags->str_args = str_cpy;
		}
	}
	else
		handle_precision_helper(input_string, i, flags);
}

void	handle_percent(char *input_string, int i, t_struct *flags)
{
	flags->chars_printed += ft_strlen(flags->str_args);
	ft_putstr(flags->str_args);
}

void	handle_space(char *input_string, int i, t_struct *flags)
{
	char	*temp;

	if ((flags->type == 'd' || flags->type == 'i') && flags->space == '1'
		&& flags->neg != '1' && flags->plus == '0')
	{
		temp = ft_strnew(1, ' ');
		if (flags->width < 0 && flags->precision < 0)
			flags->str_args = ft_strjoin(temp, flags->str_args);
		else
			flags->hash = temp;
		flags->space = '0';
	}
}

void	handle_pointer(char *input_string, int i, t_struct *flags)
{
	if (flags->flag != 'p')
	{
		flags->str_args = ft_uitoa_base(
			va_arg(flags->args, unsigned long long), 16);
		flags->str_args = ft_strjoin("0x", flags->str_args);
		flags->flag = 'p';
	}
	else
		handle_string(input_string, i, flags);
}
