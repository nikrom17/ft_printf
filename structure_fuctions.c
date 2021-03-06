/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:07:33 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 09:36:05 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void		cancel_conflicts(char *input_string, int i, t_struct *flags)
{
	if (flags->plus == '1' && flags->space == '1')
		flags->space = '0';
	if (flags->zero == '1' && flags->minus == '1')
		flags->zero = '0';
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
	while (g_table_index[input_string[++i] - 32] < 12)
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
	cancel_conflicts(input_string, i, flags);
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
	ft_strclr(flags->str_args);
	flags->c = '0';
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
	flags->str_args = NULL;
	flags->c = '0';
	flags->str_wide = NULL;
	return (flags);
}
