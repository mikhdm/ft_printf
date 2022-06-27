/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:53:24 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:07:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

int		ft_put_x(t_format *conv)
{
	unsigned int	value;
	int				length;
	const int		x = (conv->spec == SPEC_X);
	const char		*tab = (x) ? "0123456789abcdef" : "0123456789ABCDEF";

	value = va_arg(conv->ap, unsigned int);
	if (conv->precision == 0 && value == 0)
	{
		ft_putnbr_empty(conv);
		return (conv->width);
	}
	length = ft_uintlen_base(value, 16);
	if (conv->flag == FLAG_MINUS)
		ft_putuint_right(conv, tab, value, length);
	else
		ft_putuint_left(conv, tab, value, length);
	return (ft_max(3, conv->precision, conv->width, length));
}
