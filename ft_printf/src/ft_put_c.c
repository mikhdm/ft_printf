/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:49:29 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 19:51:42 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static void	ft_putuchar(unsigned char value)
{
	write(STDOUT, &value, sizeof(value));
}

int			ft_put_c(t_format *conv)
{
	int				i;
	int				length;
	unsigned char	value;

	i = 0;
	value = (unsigned char)va_arg(conv->ap, int);
	length = (int)sizeof(unsigned char);
	if (conv->flag == FLAG_MINUS)
	{
		ft_putuchar(value);
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd(' ', STDOUT);
	}
	else
	{
		if (conv->width > length)
			while (i++ < (conv->width - length))
				ft_putchar_fd(' ', STDOUT);
		ft_putuchar(value);
	}
	return (ft_max(2, conv->width, length));
}
