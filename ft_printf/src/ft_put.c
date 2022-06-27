/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:14:25 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 20:58:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static int		ft_put_percent(t_format *conv)
{
	int				i;
	int				length;
	unsigned char	padding;

	i = 0;
	length = (int)sizeof(unsigned char);
	if (conv->flag == FLAG_MINUS)
	{
		ft_putchar_fd('%', STDOUT);
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd(' ', STDOUT);
	}
	else
	{
		padding = (conv->flag == FLAG_ZERO) ? '0' : ' ';
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd(padding, STDOUT);
		ft_putchar_fd('%', STDOUT);
	}
	return (ft_max(2, conv->width, length));
}

int				ft_put(t_format *conv)
{
	int		length;

	length = 0;
	if (conv->spec == SPEC_X || conv->spec == SPEC_X_BIG)
		length = ft_put_x(conv);
	else if (conv->spec == SPEC_U)
		length = ft_put_u(conv);
	else if (conv->spec == SPEC_D || conv->spec == SPEC_I)
		length = ft_put_d(conv);
	else if (conv->spec == SPEC_C)
		length = ft_put_c(conv);
	else if (conv->spec == SPEC_S)
		length = ft_put_s(conv);
	else if (conv->spec == SPEC_P)
		length = ft_put_p(conv);
	else if (conv->spec == SPEC_PERCENT)
		length = ft_put_percent(conv);
	return (length);
}
