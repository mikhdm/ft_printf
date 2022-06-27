/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:36:38 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:13:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

void	ft_putnbr_empty(t_format *conv)
{
	int	i;

	i = 0;
	while (i++ < conv->width)
		ft_putchar_fd(' ', STDOUT);
}

void	ft_putuint_right(t_format *conv,
		const char *tab, unsigned int value, int length)
{
	int	size;
	int	i;

	i = 0;
	size = length;
	if (conv->precision > size)
	{
		while (i++ < (conv->precision - size))
			ft_putchar_fd('0', STDOUT);
		size = conv->precision;
	}
	ft_putuint_base(value, tab);
	i = 0;
	if (conv->width > size)
		while (i++ < (conv->width - size))
			ft_putchar_fd(' ', STDOUT);
}

void	ft_putuint_left(t_format *conv,
		const char *tab, unsigned int value, int length)
{
	int		i;
	int		size;

	i = 0;
	if (conv->precision < 0)
	{
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd((conv->flag == FLAG_ZERO) ? '0' : ' ', STDOUT);
	}
	else
	{
		size = (conv->precision > length) ? conv->precision : length;
		if (conv->width > size)
			while (i++ < (conv->width - size))
				ft_putchar_fd(' ', STDOUT);
		i = 0;
		while (i++ < (size - length))
			ft_putchar_fd('0', STDOUT);
	}
	ft_putuint_base(value, tab);
}
