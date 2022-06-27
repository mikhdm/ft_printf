/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:50:19 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:13:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static void	ft_put_s_empty(t_format *conv)
{
	int	i;

	i = 0;
	while (i++ < conv->width)
		ft_putchar_fd(' ', STDOUT);
}

static void	ft_put_s_right(t_format *conv, char *value)
{
	int	i;
	int size;
	int length;

	i = 0;
	length = (int)ft_strlen(value);
	if (conv->precision < 0)
	{
		ft_putstr_fd(value, STDOUT);
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd(' ', STDOUT);
	}
	else
	{
		size = ft_min(2, conv->precision, length);
		while (i < size)
			ft_putchar_fd(value[i++], STDOUT);
		i = 0;
		if (conv->width > size)
			while (i++ < (conv->width - size))
				ft_putchar_fd(' ', STDOUT);
	}
}

static void	ft_put_s_left(t_format *conv, char *value)
{
	int	i;
	int	length;
	int	size;

	i = 0;
	length = (int)ft_strlen(value);
	if (conv->precision < 0)
	{
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd(' ', STDOUT);
		ft_putstr_fd(value, STDOUT);
	}
	else
	{
		size = ft_min(2, conv->precision, length);
		if (conv->width > size)
			while (i++ < (conv->width - size))
				ft_putchar_fd(' ', STDOUT);
		i = 0;
		while (i < size)
			ft_putchar_fd(value[i++], STDOUT);
	}
}

int			ft_put_s(t_format *conv)
{
	int		size;
	int		length;
	char	*value;

	value = va_arg(conv->ap, char*);
	if ((conv->precision == 0) && !value)
	{
		ft_put_s_empty(conv);
		return (conv->width);
	}
	if (!value)
		value = NULL_STR;
	length = (int)ft_strlen(value);
	if (conv->flag == FLAG_MINUS)
		ft_put_s_right(conv, value);
	else
		ft_put_s_left(conv, value);
	size = (conv->precision < 0) ? length : ft_min(2, conv->precision, length);
	return (ft_max(2, conv->width, size));
}
