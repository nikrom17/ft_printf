/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:07:33 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 13:37:00 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void		convert_nums(char *input_string, int i, t_struct *flags)
{
	if (flags->size_modifier != '0')
		jump_table[table_index
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
	if (table_index[flags->type - 32] < 20)
		convert_nums(input_string, i, flags);
	else if (table_index[flags->type - 32] == 21)
		flags->str_args[0] = '%';
	else if (table_index[flags->type - 32] > 21)
		flags->c = va_arg(flags->args, int);
	else if (flags->type == 'S' || (flags->type == 's'
		&& flags->size_modifier == 'l'))
	{
		flags->str_wide = va_arg(flags->args, wchar_t *);
		flags->type = 'S';
	}
	else
		flags->str_args = va_arg(flags->args, char *);
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
		if ((ti = table_index[input_string[i] - 32]) > 14)
			flag = 0;
		jump_table[ti](input_string, i++, flags);
	}
	reset_struct(flags);
	return (i - 1);
}

void		pop_struct_helper(char *input_string, int i, t_struct *flags)
{
	flags->type = input_string[i];
	if (input_string[i] == 'x' || input_string[i] == 'X')
		flags->base = 16;
	if (input_string[i] == 'o' || input_string[i] == 'O')
		flags->base = 8;
	if (input_string[i] == 'U' || input_string[i] == 'D'
		|| input_string[i] == 'S' || input_string[i] == 'C')
		flags->size_modifier = 'l';
	if (input_string[i] == 'p')
		flags->size_modifier = 'P';
	if (ft_isalpha(input_string[i - 1]))
	{
		flags->size_modifier = input_string[i - 1];
		if (ft_isalpha(input_string[i - 2]))
			flags->size_modifier = ft_toupper(input_string[i - 2]);
	}
}

void		populate_struct(char *input_string, int i, t_struct *flags)
{
	while (table_index[input_string[++i] - 32] < 15)
	{
		if (input_string[i] == '.')
			flags->precision = ft_atoi(&input_string[i + 1]);
		else if (input_string[i] == '0' && flags->width < 0
			&& flags->precision < 0)
			flags->zero = '1';
		else if (ft_isdigit(input_string[i]) && flags->width < 0)
			flags->width = ft_atoi(&input_string[i]);
		else if (input_string[i] == ' ')
			flags->space = '1';
		else if (input_string[i] == '+')
			flags->plus = '1';
		else if (input_string[i] == '-')
			flags->minus = '1';
	}
	pop_struct_helper(input_string, i, flags);
}

void		cancel_conflicts(char *input_string, int i, t_struct *flags)
{
	if (flags->plus == '1' && flags->space == '1')
		flags->space = '0';
	if (flags->zero == '1' && flags->minus == '1')
		flags->zero = '0';
}

void		reset_struct(t_struct *flags)
{
	free(flags->hash);
	flags->hash = NULL;
	flags->flag = 0;
	flags->zero = '0';
	flags->plus = '0';
	flags->minus = '0';
	flags->width = -1;
	flags->base = 10;
	flags->space = '0';
	flags->precision = -1;
	flags->type = '0';
	flags->size_modifier = '0';
	flags->neg = '0';
	//free(flags->str_args);
	flags->str_args = (char *)ft_memalloc(sizeof(char) * 2);
	//ft_strclr(flags->str_args);
	//flags->str_args[0] = 0;
	//free(flags->str_wide);
	//flags->str_wide = (wchar_t *)ft_memalloc(sizeof(wchar_t) * 2);
	flags->c = '0';
}

void		free_struct(t_struct *flags)
{

	if (flags->str_args)
		free(flags->str_args);
	if (flags->hash)
		free(flags->hash);
	free(flags); 
}

t_struct	*init_struct(void)
{
	t_struct	*flags;

	flags = (t_struct *)malloc(sizeof(t_struct));
	flags->hash = NULL;
	flags->flag = 0;
	flags->zero = '0';
	flags->plus = '0';
	flags->minus = '0';
	flags->width = -1;
	flags->base = 10;
	flags->space = '0';
	flags->precision = -1;
	flags->type = '0';
	flags->size_modifier = '0';
	flags->neg = '0';
	flags->chars_printed = 0;
	flags->str_args = (char *)ft_memalloc(sizeof(char) * 2); 
	flags->c = '0';
	flags->str_wide = (char *)ft_memalloc(sizeof(char) * 2);
	return (flags);
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
			cancel_conflicts(input_string, i, flags);
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
