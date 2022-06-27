/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:18:26 by rmander           #+#    #+#             */
/*   Updated: 2021/02/01 21:08:53 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"
#include "../libft/libft.h"

void		ft_putuint_base(unsigned int n, const char *tab)
{
	unsigned int	base;

	base = ft_strlen(tab);
	if (0 <= n && n <= (base - 1))
		ft_putchar_fd(tab[n], STDOUT);
	else
	{
		ft_putuint_base(n / base, tab);
		ft_putchar_fd(tab[n % base], STDOUT);
	}
}

void		ft_putulong_base(unsigned long n, const char *tab)
{
	unsigned long	base;

	base = ft_strlen(tab);
	if (0 <= n && n <= (base - 1))
		ft_putchar_fd(tab[n], STDOUT);
	else
	{
		ft_putulong_base(n / base, tab);
		ft_putchar_fd(tab[n % base], STDOUT);
	}
}
