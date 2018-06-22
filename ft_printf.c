/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:07:33 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 09:36:54 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void		convert_nums(char *input_string, int i, t_struct *flags)
{
	if (flags->size_modifier != '0')
		g_jump_table[g_table_index
			[flags->size_modifier - 32]](input_string, i, flags);
	else if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa_base(va_arg(flags->args, int), flags->base);
	else
		flags->str_args = ft_itoa_base(
			va_arg(flags->args, unsigned int), flags->base);
	if (flags->str_args[0] == '-')
		flags->neg = '1';
}

void		find_conversion_specifier
	(char *input_string, int i, t_struct *flags)
{
	if (g_table_index[flags->type - 32] < 17)
		convert_nums(input_string, i, flags);
	else if (g_table_index[flags->type - 32] == 18)
		flags->str_args = ft_strdup("%");
	else if (g_table_index[flags->type - 32] > 18)
		flags->c = va_arg(flags->args, int);
	else if (flags->type == 'S' || (flags->type == 's'
		&& flags->size_modifier == 'l'))
	{
		flags->str_wide = va_arg(flags->args, wchar_t *);
		flags->type = 'S';
	}
	else
		flags->str_args = ft_strdup(va_arg(flags->args, char *));
	if (flags->str_args == NULL && flags->type != 'c')
		flags->str_args = ft_strdup("(null)");
}

int			handle_perc(char *input_string, int i, t_struct *flags)
{
	int		ti;
	int		flag;

	flag = 1;
	while (flag)
	{
		if ((ti = g_table_index[input_string[i] - 32]) > 11)
			flag = 0;
		g_jump_table[ti](input_string, i++, flags);
	}
	reset_struct(flags);
	return (i - 1);
}

void		free_struct(t_struct *flags)
{
	if (flags->str_args)
		free(flags->str_args);
	free(flags);
}

int			ft_printf(char *input_string, ...)
{
	int			i;
	int			chars;
	t_struct	*flags;

	flags = init_struct();
	va_start(flags->args, input_string);
	i = -1;
	while (input_string[++i])
	{
		if (input_string[i] == '%')
		{
			populate_struct(input_string, i, flags);
			find_conversion_specifier(input_string, i, flags);
			i = handle_perc(input_string, ++i, flags);
		}
		else
		{
			flags->chars_printed++;
			write(1, &input_string[i], 1);
		}
	}
	chars = flags->chars_printed;
	va_end(flags->args);
	free_struct(flags);
	return (chars);
}
