/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 02:36:43 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 20:56:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

int		ft_isflag(int c)
{
	if (ft_isdigit(c) ||
		c == FLAG_MINUS ||
		c == FLAG_STAR ||
		c == FLAG_DOT)
		return (TRUE);
	return (FALSE);
}

int		ft_isspec(int c)
{
	if (c == SPEC_C ||
		c == SPEC_S ||
		c == SPEC_P ||
		c == SPEC_D ||
		c == SPEC_I ||
		c == SPEC_U ||
		c == SPEC_X ||
		c == SPEC_X_BIG ||
		c == SPEC_PERCENT)
		return (TRUE);
	return (FALSE);
}

int		ft_uintlen_base(unsigned int n, const unsigned int base)
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

int		ft_max(size_t len, ...)
{
	int		max;
	int		curr;
	va_list	ap;

	va_start(ap, len);
	max = va_arg(ap, int);
	curr = max;
	while (--len)
	{
		curr = va_arg(ap, int);
		if (curr > max)
			max = curr;
	}
	va_end(ap);
	return (max);
}

int		ft_min(size_t len, ...)
{
	int		min;
	int		curr;
	va_list	ap;

	va_start(ap, len);
	min = va_arg(ap, int);
	curr = min;
	while (--len)
	{
		curr = va_arg(ap, int);
		if (curr < min)
			min = curr;
	}
	va_end(ap);
	return (min);
}
