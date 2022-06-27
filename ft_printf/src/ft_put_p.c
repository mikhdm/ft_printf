/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:38:33 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 20:59:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static int	ft_ulonglen_base(unsigned long n, const unsigned long base)
{
	int	size;

	size = 0;
	if (!n)
		return (++size);
	while (n)
	{
		n /= base;
		++size;
	}
	return (size);
}

static void	ft_put_null_zp(t_format *conv)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen("0x");
	if (conv->flag == FLAG_MINUS)
		ft_putstr_fd("0x", STDOUT);
	if (conv->width > size)
		while (i++ < (conv->width - size))
			ft_putchar_fd(' ', STDOUT);
	if (conv->flag != FLAG_MINUS)
		ft_putstr_fd("0x", STDOUT);
}

static void	ft_putulong_prefixed(unsigned long value)
{
	ft_putstr_fd("0x", STDOUT);
	ft_putulong_base(value, "0123456789abcdef");
}

int			ft_put_p(t_format *conv)
{
	void			*value;
	int				i;
	int				length;
	int				size;

	i = 0;
	value = va_arg(conv->ap, void*);
	length = ft_ulonglen_base((unsigned long)value, 16);
	size = ft_strlen("0x");
	if ((conv->precision == 0) && !value)
	{
		ft_put_null_zp(conv);
		return (ft_max(2, conv->width, size));
	}
	size += length;
	if (conv->flag == FLAG_MINUS)
		ft_putulong_prefixed((unsigned long)value);
	if (conv->width > size)
		while (i++ < (conv->width - size))
			ft_putchar_fd(' ', STDOUT);
	if (conv->flag != FLAG_MINUS)
		ft_putulong_prefixed((unsigned long)value);
	return (ft_max(2, conv->width, size));
}
