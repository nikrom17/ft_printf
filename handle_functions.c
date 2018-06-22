/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:39:35 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 09:35:06 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_integer(char *input_string, int i, t_struct *flags)
{
	int		len;

	len = ft_strlen(flags->str_args);
	flags->chars_printed += len;
	write(1, flags->str_args, len);
	flags->str_args = NULL;
}

void	handle_string(char *input_string, int i, t_struct *flags)
{
	int		j;
	int		len;

	j = -1;
	len = ft_strlen(flags->str_args);
	flags->chars_printed += len;
	if (flags->type == 's')
		write(1, flags->str_args, len);
	else
	{
		while (flags->str_wide[++j])
		{
			flags->c = flags->str_wide[j];
			handle_wcharacter(input_string, i, flags);
		}
	}
	flags->str_args = NULL;
}

void	handle_width_helper(char fill, int len, t_struct *flags)
{
	char	*temp;
	char	*str;

	if (flags->width > flags->precision &&
		g_table_index[flags->type - 32] < 20
			&& flags->zero == '1' && flags->precision >= 0)
		fill = ' ';
	str = ft_strnew(flags->width, fill);
	str[len] = 0;
	if (flags->plus == '1' || (flags->neg == '1' && fill == '0'))
	{
		if (flags->neg == '1')
			str[0] = '-';
		else
			str[0] = '+';
		flags->str_args[0] = fill;
	}
	if (flags->hash)
		str = ft_strrplc(str, flags->hash);
	temp = ft_strjoin(str, flags->str_args);
	free(flags->str_args);
	free(str);
	flags->str_args = temp;
}

char	handle_width_helper_2(char *input_string, int i, t_struct *flags)
{
	char	fill;

	flags->flag = 1;
	if (flags->zero == '1')
		fill = '0';
	else
		fill = ' ';
	if (flags->precision >= 0)
		handle_precision(input_string, i, flags);
	return (fill);
}

void	handle_width(char *input_string, int i, t_struct *flags)
{
	int		len;
	char	fill;
	char	*temp;

	if (!flags->str_args)
		flags->str_args = ft_strnew(1, 0);
	if (!flags->flag)
	{
		fill = handle_width_helper_2(input_string, i, flags);
		if ((len = flags->width - ft_strlen(flags->str_args)) > 0)
		{
			if (flags->minus == '1')
			{
				temp = ft_strjoin(flags->str_args, ft_strnew(len, fill));
				free(flags->str_args);
				flags->str_args = temp;
			}
			else
				handle_width_helper(fill, len, flags);
		}
	}
}
