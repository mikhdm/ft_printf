/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:51:10 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:12:38 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

int	ft_put_u(t_format *conv)
{
	const char		*tab = "0123456789";
	unsigned int	value;
	int				length;

	value = va_arg(conv->ap, unsigned int);
	if (conv->precision == 0 && value == 0)
	{
		ft_putnbr_empty(conv);
		return (conv->width);
	}
	length = ft_uintlen_base(value, 10);
	if (conv->flag == FLAG_MINUS)
		ft_putuint_right(conv, tab, value, length);
	else
		ft_putuint_left(conv, tab, value, length);
	return (ft_max(3, conv->precision, conv->width, length));
}
