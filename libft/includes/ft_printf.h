/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:59:56 by nroman            #+#    #+#             */
/*   Updated: 2018/06/04 16:54:00 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct		s_flags 
{
	char			hash;
	char			zero;
	char			plus;
	char			minus;
	int				base;
	char			type;
	char			*str_args;
	va_list			args;
	int			chars_printed;
}					t_struct;

typedef void (*create_j_table)(char *, int, t_struct *);

static const int table_index[] =
{
  /* ' ' */  1,            0,            0, /* '#' */  0,
             0, /* '%' */ 21,            0, /* '\''*/  6,
             0,            0, /* '*' */  7, /* '+' */  4,
             0, /* '-' */  5, /* '.' */  3,            0,
  /* '0' */  1, /* '1' */  2, /* '2' */  2, /* '3' */  2,
  /* '4' */  2, /* '5' */  2, /* '6' */  2, /* '7' */  2,
  /* '8' */  2, /* '9' */  2,            0,            0,
             0,            0,            0,            0,
             0, /* 'A' */  0,            0, /* 'C' */  0,
             0, /* 'E' */  0, /* F */    0, /* 'G' */  0,
  /* 'H' */ 10, /* 'I' */  0,            0,            0,
  /* 'L' */ 12,            0,            0, /* 'O' */ 17,
             0,            0,            0, /* 'S' */  0,
             0,            0,            0,            0,
  /* 'X' */ 18,            0, /* 'Z' */  0,            0,
             0,            0,            0,            0,
             0, /* 'a' */  0,            0, /* 'c' */  0,
  /* 'd' */ 15, /* 'e' */  0, /* 'f' */  0, /* 'g' */  0,
  /* 'h' */  9, /* 'i' */ 15, /* 'j' */ 13,            0,
  /* 'l' */ 11, /* 'm' */  0, /* 'n' */  0, /* 'o' */ 17,
  /* 'p' */  0, /* 'q' */  0,            0, /* 's' */ 19,
  /* 't' */  0, /* 'u' */  0,            0,            0,
  /* 'x' */ 18,            0, /* 'z' */ 14,            0,
             0,            0,            0,            0,
             0
};

int	ft_printf(char *input_string, ...);
int	handle_perc(char *input_string, int i, t_struct *flags);
void	find_conversion_specifier(char *input_string, int i, t_struct *flags);
void	handle_space(char *input_string, int i, t_struct *flags);
void	handle_percent(char *input_string, int i, t_struct *flags);
void	handle_plus(char *input_string, int i, t_struct *flags);
void	handle_minus(char *input_string, int i, t_struct *flags); 
void	handle_hash(char *input_string, int i, t_struct *flags);   
void	handle_zero(char *input_string, int i, t_struct *flags);
void	handle_backslash(char *input_string, int i, t_struct *flags);
void	handle_asterisk(char *input_string, int i, t_struct *flags);
void	handle_width(char *input_string, int i, t_struct *flags);
void	handle_precision(char *input_string, int i, t_struct *flags);
void	handle_hh(char *input_string, int i, t_struct *flags);
void	handle_h(char *input_string, int i, t_struct *flags);
void	handle_l(char *input_string, int i, t_struct *flags);
void	handle_ll(char *input_string, int i, t_struct *flags);
void	handle_j(char *input_string, int i, t_struct *flags);
void	handle_z(char *input_string, int i, t_struct *flags);
void	handle_integer(char *input_string, int i, t_struct *flags);
void	handle_unsigned(char *input_string, int i, t_struct *flags);
void	handle_octal(char *input_string, int i, t_struct *flags);
void	handle_hex(char *input_string, int i, t_struct *flags);
void	handle_float(char *input_string, int i, t_struct *flags);
void	handle_character(char *input_string, int i, t_struct *flags);
void	handle_string(char *input_string, int i, t_struct *flags);
void	handle_pointer(char *input_string, int i, t_struct *flags);
void	handle_wcharacter(char *input_string, int i, t_struct *flags);

#endif //ft_printf
