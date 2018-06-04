/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:57:25 by nroman            #+#    #+#             */
/*   Updated: 2018/06/02 08:16:56 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

create_j_table jump_table[25] =
{
	handle_hash,            /* for '#' */
	handle_zero,            /* for '0' */
	handle_width,           /* for '1'...'9' */
	handle_precision,       /* for '.' */
	handle_plus,            /* for '+' */
	handle_minus,           /* for '-' */
	handle_space,           /* for ' ' */
	handle_backslash,       /* for '\' */
	handle_asterisk,        /* for '*' */
	handle_hh,              /* for 'hh' */
	handle_h,               /* for 'h' */
	handle_l,               /* for 'l' */
	handle_ll,              /* for 'L', 'q' */
	handle_j,               /* for 'j' */
	handle_z,               /* for 'z'*/
	//Converson Specifiers: start 15
	//ints
	handle_integer,         /* for 'd', 'i' */
	handle_unsigned,        /* for 'u' */
	handle_octal,           /* for 'o' */
	handle_hex,             /* for 'X', 'x' */
	handle_pointer,         /* for 'p' */
	//strings start 20
	handle_string,          /* for 's', 'S' */
	handle_percent,         /* for '%' */
	handle_character,       /* for 'c' */
	handle_wcharacter,      /* for 'C' */
 };

void	check_length_mod(char *input_string, int i, t_struct *flags)
{
	char	modifier;

	modifier = 0;
	if (input_string[i] == 'x' || input_string[i] == 'X')
		flags->base = 16;
	else
		flags->base = 8;
	if (ft_isalpha(input_string[--i]))
		modifier = input_string[i];
	if (ft_isalpha(input_string[--i]))
		modifier = input_string[i];
	if (modifier)
		jump_table[modifier - 32](input_string, i, flags);
	else
		flags->str_args = ft_itoa_base(va_arg(flags->args, int), flags->base);
}

void	find_conversion_specifier(char *input_string, int i, t_struct *flags)
{
	while (table_index[input_string[i] - 32] < 14)
		i++;
	flags->type = input_string[i];
	if (table_index[input_string[i] - 32] < 20)
		check_length_mod(input_string, i, flags);
	else if (table_index[input_string[i] - 32] == 21) //%%
		return ;
	else
		flags->str_args = va_arg(flags->args, char *);
}

int		handle_perc(char *input_string, int i, t_struct *flags)
{
	int		TI;
	int		flag;

	flag = 1;
	while (flag)
	{
		if ((TI = table_index[input_string[i] - 32]) > 13)
		{
			flag = 0;
		}
		jump_table[TI](input_string, i++, flags);
	}
	return (i - 1);
}

t_struct	*init_struct(void)
{
	t_struct	*flags;

	flags =(t_struct *)malloc(sizeof(t_struct));
	flags->hash = '0';
	flags->zero = '0';
	flags->plus = '0';
	flags->minus = '0';
	flags->base = 10;
	flags->type = '0';
	flags->chars_printed = 0;
	flags->str_args = NULL;
	return (flags);
}

int	ft_printf(char *input_string, ...)
{
	int			i;
	t_struct	*flags;

	flags = init_struct();
	va_start(flags->args, input_string);
	i = -1;
	while (input_string[++i])
	{
		if (input_string[i] == '%')
		{
			i++;
			find_conversion_specifier(input_string, i, flags);
			i = handle_perc(input_string, i, flags);
		}
		else
		{
			flags->chars_printed++;
			write(1, &input_string[i], 1);
		}
	}
	va_end(flags->args);
	return (flags->chars_printed);
}
