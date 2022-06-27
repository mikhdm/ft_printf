/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:04:12 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:01:15 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

const char	*ft_parse_flag(t_format *conv, const char *fmt)
{
	while (*fmt && (*fmt == FLAG_MINUS || *fmt == FLAG_ZERO))
	{
		if (*fmt == FLAG_ZERO)
			conv->flag = FLAG_ZERO;
		else if (*fmt == FLAG_MINUS)
		{
			conv->flag = FLAG_MINUS;
			break ;
		}
		++fmt;
	}
	while (*fmt && (*fmt == FLAG_MINUS || *fmt == FLAG_ZERO))
		++fmt;
	return (fmt);
}

const char	*ft_parse_width(t_format *conv, const char *fmt)
{
	int tmp;

	tmp = 0;
	if (*fmt == FLAG_STAR)
	{
		tmp = va_arg(conv->ap, int);
		if (tmp < 0)
		{
			conv->flag = FLAG_MINUS;
			conv->width = tmp * (-1);
		}
		else
			conv->width = tmp;
		++fmt;
	}
	else
	{
		conv->width = ft_atoi(fmt);
		while (*fmt && ft_isdigit(*fmt))
			++fmt;
	}
	return (fmt);
}

const char	*ft_parse_precision(t_format *conv, const char *fmt)
{
	int	tmp;

	tmp = 0;
	if (*fmt == FLAG_DOT)
	{
		++fmt;
		if (*fmt == FLAG_STAR)
		{
			tmp = va_arg(conv->ap, int);
			if (tmp >= 0)
				conv->precision = tmp;
			++fmt;
		}
		else
		{
			conv->precision = ft_isdigit(*fmt) ? ft_atoi(fmt) : 0;
			while (*fmt && ft_isdigit(*fmt))
				++fmt;
		}
	}
	return (fmt);
}
