/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:29:01 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 20:55:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static void		ft_reset(t_format *conv)
{
	conv->width = 0;
	conv->precision = -1;
	conv->spec = '\0';
	conv->flag = '\0';
}

int				ft_printf(const char *fmt, ...)
{
	t_format	conv;
	int			length;

	conv = (t_format) {.flag = '\0', .spec = '\0', .width = 0, .precision = -1};
	va_start(conv.ap, fmt);
	length = 0;
	while (*fmt)
	{
		if (*fmt == FMT_START)
		{
			ft_reset(&conv);
			ft_parse(&conv, fmt);
			length += ft_put(&conv);
			++fmt;
			while (*fmt && (ft_isflag(*fmt)))
				++fmt;
			if (ft_isspec(*fmt))
				++fmt;
			continue ;
		}
		ft_putchar_fd(*fmt++, STDOUT);
		++length;
	}
	va_end(conv.ap);
	return (length);
}
