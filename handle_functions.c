/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:39:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/02 08:29:14 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_integer(char *input_string, int i, t_struct *flags)
{
	ft_putstr(flags->str_args);
}

void	handle_string(char *input_string, int i, t_struct *flags)
{
	ft_putstr(flags->str_args);
}

void	handle_width(char *input_string, int i, t_struct *flags)
{
	int		len;
	char	*str;
	char	fill;

	if (flags->zero == '1')
		fill = '0';
	else
		fill = ' ';
	if ((len = (ft_atoi(&input_string[i]) - ft_strlen(flags->str_args))) > 0)
	{
		if (flags->minus == '1')
		{
			str = ft_strnew(len, fill);
			flags->str_args = ft_strjoin(flags->str_args, str);
		}
		else
		{
			str = ft_strnew(input_string[i], fill);
			str[len] = 0;
			if (flags->plus)
			{
				str[0] = '+';
				flags->str_args[0] = fill;
			}
			flags->str_args = ft_strcat(str, flags->str_args);
		}
		free(str);
	}
}

void    handle_precision(char *input_string, int i, t_struct *flags)
{

}

void	handle_plus(char *input_string, int i, t_struct *flags)
{
	char	*plus;

	flags->plus = '1';
	plus = ft_strnew(1, '+');
	if (flags->str_args[0] == '-')
		return ;
	else
		flags->str_args = ft_strjoin(plus, flags->str_args);
		//str is malloced in strjoin
		//free(str);
		free(plus);
}

void	handle_percent(char *input_string, int i, t_struct *flags)
{
	write(1, "%", 1);
}

void	handle_minus(char *input_string, int i, t_struct *flags)
{
	flags->minus = '1';
}

void	handle_zero(char *input_string, int i, t_struct *flags)
{
	flags->zero = '1';
}


void	handle_space(char *input_string, int i, t_struct *flags)
{
	//code here
}

void	handle_hash(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'x')
	{
		flags->str_args = ft_strjoin("0x", flags->str_args);
	}
	else if (flags->type == 'X')
	{
		flags->str_args = ft_strjoin("0X", flags->str_args);
	}
	else
		flags->str_args = ft_strjoin("0", flags->str_args);
}

void	handle_backslash(char *input_string, int i, t_struct *flags)
{
	//code here
}

void	handle_asterisk(char *input_string, int i, t_struct *flags)
{
	//code here
}

void	handle_h(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa((short)va_arg(flags->args, int));
	else
		flags->str_args = ft_itoa((unsigned short)va_arg(flags->args, int));
}

void	handle_hh(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa((signed char)va_arg(flags->args, int));
	else
		flags->str_args = ft_itoa((unsigned char)va_arg(flags->args, int));
}

void	handle_l(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa(va_arg(flags->args, long));
	else
		flags->str_args = ft_itoa(va_arg(flags->args, unsigned long));
}

void	handle_ll(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa(va_arg(flags->args, long long));
	else
		flags->str_args = ft_itoa(va_arg(flags->args, unsigned long long));
}

void	handle_j(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa(va_arg(flags->args, intmax_t));
	else
		flags->str_args = ft_itoa(va_arg(flags->args, uintmax_t));
}

void	handle_z(char *input_string, int i, t_struct *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		flags->str_args = ft_itoa(va_arg(flags->args, size_t));
	else
		flags->str_args = ft_itoa(va_arg(flags->args, size_t));
}

void	handle_unsigned(char *input_string, int i, t_struct *flags)
{
	//code here
}

void	handle_octal(char *input_string, int i, t_struct *flags)
{		
	int		j;
	j = -1;
	if (input_string[i] == 'O')
	{
		while(flags->str_args[++j])
			flags->str_args[j] = ft_toupper(flags->str_args[j]);
	}
	ft_putstr(flags->str_args);
}

void	handle_hex(char *input_string, int i, t_struct *flags)
{
	int		j;
	j = -1;
	if (input_string[i] == 'X')
	{
		while(flags->str_args[++j])
			flags->str_args[j] = ft_toupper(flags->str_args[j]);
	}
	ft_putstr(flags->str_args);
}

void	handle_float(char *input_string, int i, t_struct *flags)
{
	//code here
}

void	handle_character(char *input_string, int i, t_struct *flags)
{
	//code here
}

void	handle_pointer(char *input_string, int i, t_struct *flags)
{
/*
    int		i;
    uintptr_t	p;
    
    p = (uintptr_t)p0;

    write_char('0'); 
    write_char('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
        write_char(hex_digit((p >> i) & 0xf));
    } */
}

void	handle_wcharacter(char *input_string, int i, t_struct *flags)
{
	//code here
}
