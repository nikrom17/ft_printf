/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:59:56 by nroman            #+#    #+#             */
/*   Updated: 2018/06/21 20:01:36 by nroman           ###   ########.fr       */
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
  /* ' ' */  4,            0,            0, /* '#' */  0,
             0, /* '%' */ 17,            0, /* '\''*/  0,
             0,            0, /* '*' */  0, /* '+' */  3,
             0, /* '-' */  5, /* '.' */  2,            0,
  /* '0' */ 20, /* '1' */  1, /* '2' */  1, /* '3' */  1,
  /* '4' */  1, /* '5' */  1, /* '6' */  1, /* '7' */  1,
  /* '8' */  1, /* '9' */  1,            0,            0,
             0,            0,            0,            0,
             0, /* 'A' */  0,            0, /* 'C' */ 19,
  /* 'D' */ 11, /* 'E' */  0, /* F */    0, /* 'G' */  0,
  /* 'H' */  6, /* 'I' */  0,            0,            0,
  /* 'L' */  8,            0,            0, /* 'O' */ 13,
  /* 'P' */ 15,            0,            0, /* 'S' */ 16,
             0, /* 'U' */ 12,            0,            0,
  /* 'X' */ 14,            0, /* 'Z' */  0,            0,
             0,            0,            0,            0,
             0, /* 'a' */  0,            0, /* 'c' */ 18,
  /* 'd' */ 11, /* 'e' */ 20, /* 'f' */ 20, /* 'g' */ 20,
  /* 'h' */  5, /* 'i' */ 11, /* 'j' */  9,            0,
  /* 'l' */  7, /* 'm' */  0, /* 'n' */ 20, /* 'o' */ 13,
  /* 'p' */ 11, /* 'q' */  0,            0, /* 's' */ 16,
  /* 't' */ 20, /* 'u' */ 12,            0,            0,
  /* 'x' */ 14,            0, /* 'z' */ 10,            0,
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
void	handle_hash(char *input_string, int i, t_struct *flags);   
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
void	handle_character(char *input_string, int i, t_struct *flags);
void	handle_string(char *input_string, int i, t_struct *flags);
void	handle_pointer(char *input_string, int i, t_struct *flags);
void	handle_wcharacter(char *input_string, int i, t_struct *flags);
void	pass(char *input_string, int i, t_struct *flags);

static const create_j_table jump_table[25] =
{
	handle_hash,            /* for '#' */
	handle_width,           /* for '1'...'9' */
	handle_precision,       /* for '.' */
	handle_plus,            /* for '+' */
	handle_space,           /* for ' ' */
	handle_hh,              /* for 'hh' */
	handle_h,               /* for 'h' */
	handle_l,               /* for 'l' */
	handle_ll,              /* for 'L', 'q' */
	handle_j,               /* for 'j' */
	handle_z,               /* for 'z'*/
	//Converson Specifiers: start 11
	//ints
	handle_integer,         /* for 'd', 'i' */
	handle_unsigned,        /* for 'u' , 'U'*/
	handle_octal,           /* for 'o' */
	handle_hex,             /* for 'X', 'x' */
	handle_pointer,         /* for 'p' */
	//strings start 16
	handle_string,          /* for 's', 'S' */
	handle_percent,         /* for '%' */
	handle_character,       /* for 'c' */
	handle_wcharacter,      /* for 'C' */
	pass
};
#endif //ft_printf
