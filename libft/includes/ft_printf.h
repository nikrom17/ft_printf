/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:59:56 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 11:27:05 by nroman           ###   ########.fr       */
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

typedef void (*create_j_table)(char *, int, t_struct *);

static const int table_index[] =
{
  /* ' ' */  6,            0,            0, /* '#' */  0,
             0, /* '%' */ 21,            0, /* '\''*/  0,
             0,            0, /* '*' */  0, /* '+' */  4,
             0, /* '-' */  5, /* '.' */  8,            0,
  /* '0' */  1, /* '1' */  2, /* '2' */  2, /* '3' */  2,
  /* '4' */  2, /* '5' */  2, /* '6' */  2, /* '7' */  2,
  /* '8' */  2, /* '9' */  2,            0,            0,
             0,            0,            0,            0,
             0, /* 'A' */  0,            0, /* 'C' */ 23,
  /* 'D' */ 15, /* 'E' */  0, /* F */    0, /* 'G' */  0,
  /* 'H' */  9, /* 'I' */  0,            0,            0,
  /* 'L' */ 12,            0,            0, /* 'O' */ 17,
  /* 'P' */ 19,            0,            0, /* 'S' */ 20,
             0, /* 'U' */ 16,            0,            0,
  /* 'X' */ 18,            0, /* 'Z' */  0,            0,
             0,            0,            0,            0,
             0, /* 'a' */  0,            0, /* 'c' */ 22,
  /* 'd' */ 15, /* 'e' */  0, /* 'f' */  0, /* 'g' */  0,
  /* 'h' */ 10, /* 'i' */ 15, /* 'j' */ 13,            0,
  /* 'l' */ 11, /* 'm' */  0, /* 'n' */  0, /* 'o' */ 17,
  /* 'p' */ 16, /* 'q' */  0,            0, /* 's' */ 20,
  /* 't' */  0, /* 'u' */ 16,            0,            0,
  /* 'x' */ 18,            0, /* 'z' */ 14,            0,
             0,            0,            0,            0,
             0
};

int		ft_printf(char *input_string, ...);
void	convert_nums(char *input_string, int i, t_struct *flags);
int		handle_perc(char *input_string, int i, t_struct *flags);
void	reset_struct(t_struct *flags);
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

static const create_j_table jump_table[25] =
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
	handle_unsigned,        /* for 'u' , 'U'*/
	handle_octal,           /* for 'o' */
	handle_hex,             /* for 'X', 'x' */
	handle_pointer,         /* for 'p' */
	//strings start 20
	handle_string,          /* for 's', 'S' */
	handle_percent,         /* for '%' */
	handle_character,       /* for 'c' */
	handle_wcharacter,      /* for 'C' */
};
#endif //ft_printf
