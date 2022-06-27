/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:49:44 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:13:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static void		ft_put_right(t_format *conv,
				unsigned int value, int length, int neg)
{
	int	size;
	int	i;

	if (neg)
		ft_putchar_fd('-', STDOUT);
	i = 0;
	size = length;
	if (conv->precision > size)
	{
		while (i++ < (conv->precision - size))
			ft_putchar_fd('0', STDOUT);
		size = conv->precision;
	}
	ft_putuint_base(value, "0123456789");
	i = 0;
	size += (neg) ? 1 : 0;
	if (conv->width > size)
		while (i++ < (conv->width - size))
			ft_putchar_fd(' ', STDOUT);
}

static void		ft_put_left_np(t_format *conv, int length, int neg)
{
	int	i;
	int size;

	i = 0;
	size = (neg) ? length + 1 : length;
	if (neg && conv->flag == FLAG_ZERO)
		ft_putchar_fd('-', STDOUT);
	if (conv->width > size)
		while (i++ < (conv->width - size))
			ft_putchar_fd((conv->flag == FLAG_ZERO) ? '0' : ' ', STDOUT);
	if (neg && conv->flag != FLAG_ZERO)
		ft_putchar_fd('-', STDOUT);
}

static void		ft_put_left(t_format *conv,
				unsigned int value, int length, int neg)
{
	int		i;
	int		size;

	i = 0;
	if (conv->precision < 0)
		ft_put_left_np(conv, length, neg);
	else
	{
		size = (conv->precision > length) ? conv->precision : length;
		size += (neg) ? 1 : 0;
		if (conv->width > size)
			while (i++ < (conv->width - size))
				ft_putchar_fd(' ', STDOUT);
		if (neg)
			ft_putchar_fd('-', STDOUT);
		i = 0;
		size -= (neg) ? 1 : 0;
		while (i++ < (size - length))
			ft_putchar_fd('0', STDOUT);
	}
	ft_putuint_base(value, "0123456789");
}

int				ft_put_d(t_format *conv)
{
	unsigned int	uvalue;
	int				value;
	int				length;
	int				neg;

	value = va_arg(conv->ap, int);
	if (conv->precision == 0 && value == 0)
	{
		ft_putnbr_empty(conv);
		return (conv->width);
	}
	neg = (value < 0) ? TRUE : FALSE;
	uvalue = (neg) ? value * (-1) : value;
	length = ft_uintlen_base(uvalue, 10);
	if (conv->flag == FLAG_MINUS)
		ft_put_right(conv, uvalue, length, neg);
	else
		ft_put_left(conv, uvalue, length, neg);
	length += (neg) ? 1 : 0;
	return (ft_max(3, (neg) ? (conv->precision + 1) : conv->precision,
			conv->width,
			length));
}
