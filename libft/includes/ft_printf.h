/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:59:56 by nroman            #+#    #+#             */
/*   Updated: 2018/06/22 09:28:20 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct		s_flags
{
	char			*hash;
	int				flag;
	char			zero;
	char			plus;
	char			minus;
	int				width;
	int				base;
	char			space;
	int				precision;
	char			type;
	char			size_modifier;
	char			neg;
	char			*str_args;
	char			c;
	va_list			args;
	int				chars_printed;
	wchar_t			*str_wide;
}					t_struct;

typedef void		(*t_create_j_table)(char *, int, t_struct *);

static const int	g_table_index[] =
{
	5, 0, 0, 1,
	0, 18, 0, 0,
	0, 0, 0, 4,
	0, 6, 7, 0,
	0, 2, 2, 2,
	2, 2, 2, 2,
	2, 2, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 20,
	12, 0, 0, 0,
	6, 0, 0, 0,
	9, 0, 0, 14,
	16, 0, 0, 17,
	0, 13, 0, 0,
	15, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 19,
	12, 0, 0, 0,
	7, 12, 10, 0,
	8, 0, 0, 14,
	12, 0, 0, 17,
	0, 13, 0, 0,
	15, 0, 11, 0,
	0, 0, 0, 0,
	0
};

int					ft_printf(char *input_string, ...);
void				convert_nums(char *input_string, int i, t_struct *flags);
int					handle_perc(char *input_string, int i, t_struct *flags);
void				reset_struct(t_struct *flags);
void				find_conversion_specifier
						(char *input_string, int i, t_struct *flags);
void				handle_space(char *input_string, int i, t_struct *flags);
void				handle_percent(char *input_string, int i, t_struct *flags);
void				handle_plus(char *input_string, int i, t_struct *flags);
void				handle_hash(char *input_string, int i, t_struct *flags);
void				handle_width(char *input_string, int i, t_struct *flags);
void				handle_precision
						(char *input_string, int i, t_struct *flags);
void				handle_hh(char *input_string, int i, t_struct *flags);
void				handle_h(char *input_string, int i, t_struct *flags);
void				handle_l(char *input_string, int i, t_struct *flags);
void				handle_ll(char *input_string, int i, t_struct *flags);
void				handle_j(char *input_string, int i, t_struct *flags);
void				handle_z(char *input_string, int i, t_struct *flags);
void				handle_integer(char *input_string, int i, t_struct *flags);
void				handle_unsigned(char *input_string, int i, t_struct *flags);
void				handle_octal(char *input_string, int i, t_struct *flags);
void				handle_hex(char *input_string, int i, t_struct *flags);
void				handle_character
						(char *input_string, int i, t_struct *flags);
void				handle_string(char *input_string, int i, t_struct *flags);
void				handle_pointer(char *input_string, int i, t_struct *flags);
void				handle_wcharacter
						(char *input_string, int i, t_struct *flags);
void				pass(char *input_string, int i, t_struct *flags);
t_struct			*init_struct(void);
void				populate_struct(char *input_string, int i, t_struct *flags);

static const		t_create_j_table g_jump_table[25] =
{
	pass,
	handle_hash,
	handle_width,
	handle_precision,
	handle_plus,
	handle_space,
	handle_hh,
	handle_h,
	handle_l,
	handle_ll,
	handle_j,
	handle_z,
	handle_integer,
	handle_unsigned,
	handle_octal,
	handle_hex,
	handle_pointer,
	handle_string,
	handle_percent,
	handle_character,
	handle_wcharacter
};
#endif
