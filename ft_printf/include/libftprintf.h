/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:28:54 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 19:47:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# define FMT_START '%'

# define FLAG_ZERO '0'
# define FLAG_MINUS '-'
# define FLAG_DOT '.'
# define FLAG_STAR '*'

# define SPEC_C 'c'
# define SPEC_S 's'
# define SPEC_P 'p'
# define SPEC_D 'd'
# define SPEC_I 'i'
# define SPEC_U 'u'
# define SPEC_X 'x'
# define SPEC_X_BIG 'X'
# define SPEC_PERCENT '%'

# define STDOUT 1

# define NULL_STR "(null)"

typedef struct		s_format
{
	va_list			ap;
	char			flag;
	char			spec;
	int				width;
	int				precision;
}					t_format;

/*
** ft_printf_utils.c - overall project utility functions
*/

int					ft_isflag(int c);
int					ft_isspec(int c);
int					ft_uintlen_base(unsigned int n, const unsigned int base);
int					ft_max(size_t len, ...);
int					ft_min(size_t len, ...);

/*
** ft_putnbr_base.c - number printing in base utility functions
*/

void				ft_putuint_base(unsigned int n, const char *tab);
void				ft_putulong_base(unsigned long n, const char *tab);

/*
** ft_parse_utils.c - parser helper functions
*/

const char			*ft_parse_flag(t_format *conv, const char *fmt);
const char			*ft_parse_width(t_format *conv, const char *fmt);
const char			*ft_parse_precision(t_format *conv, const char *fmt);

/*
** ft_put_utils.c - number printing helper functions
*/

void				ft_putnbr_empty(t_format *conv);
void				ft_putuint_left(t_format *conv,
					const char *tab, unsigned int value, int length);
void				ft_putuint_right(t_format *conv,
					const char *tab, unsigned int value, int length);

int					ft_put_c(t_format *conv);
int					ft_put_s(t_format *conv);
int					ft_put_p(t_format *conv);
int					ft_put_d(t_format *conv);
int					ft_put_u(t_format *conv);
int					ft_put_x(t_format *conv);

int					ft_put(t_format *conv);
t_format			ft_parse(t_format *conv, const char *fmt);
int					ft_printf(const char *fmt, ...);

#endif
