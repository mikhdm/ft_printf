/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:32:56 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 19:49:26 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libftprintf.h"
#include "../libft/libft.h"

static const char	*ft_parse_flags(t_format *conv, const char *fmt)
{
	++fmt;
	fmt = ft_parse_flag(conv, fmt);
	fmt = ft_parse_width(conv, fmt);
	fmt = ft_parse_precision(conv, fmt);
	return (fmt);
}

static const char	*ft_parse_spec(t_format *conv, const char *fmt)
{
	if (*fmt == SPEC_C ||
		*fmt == SPEC_S ||
		*fmt == SPEC_P ||
		*fmt == SPEC_D ||
		*fmt == SPEC_I ||
		*fmt == SPEC_U ||
		*fmt == SPEC_X ||
		*fmt == SPEC_X_BIG ||
		*fmt == SPEC_PERCENT)
		conv->spec = *fmt;
	++fmt;
	return (fmt);
}

t_format			ft_parse(t_format *conv, const char *fmt)
{
	fmt = ft_parse_flags(conv, fmt);
	fmt = ft_parse_spec(conv, fmt);
	return (*conv);
}
