/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 23:34:00 by marvin            #+#    #+#             */
/*   Updated: 2019/05/29 00:58:09 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putc0(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putc1(int c)
{
	unsigned char	d;
	unsigned char	e;

	e = 128 + (c & 63);
	c = c >> 6;
	d = 128 + 64 + c;
	write(1, &d, 1);
	write(1, &e, 1);
	return (2);
}

static int	ft_putc2(int c)
{
	unsigned char	d;
	unsigned char	e;
	unsigned char	f;

	f = 128 + (c & 63);
	c = c >> 6;
	e = 128 + (c & 63);
	c = c >> 6;
	d = 128 + 64 + 32 + c;
	write(1, &d, 1);
	write(1, &e, 1);
	write(1, &f, 1);
	return (3);
}

static int	ft_putc3(int c)
{
	unsigned char	q;
	unsigned char	w;
	unsigned char	e;
	unsigned char	r;

	r = 128 + (c & 63);
	c = c >> 6;
	e = 128 + (c & 63);
	c = c >> 6;
	w = 128 + (c & 63);
	c = c >> 6;
	q = 128 + 64 + 32 + 16 + c;
	write(1, &q, 1);
	write(1, &w, 1);
	write(1, &e, 1);
	write(1, &r, 1);
	return (4);
}

int			ft_prin_c(int a)
{
	static int b;

	if (a < 128)
		b += ft_putc0(a);
	else if (a >= 128 && a < 2048)
		b += ft_putc1(a);
	else if (a >= 2048 && a < 65536)
		b += ft_putc2(a);
	else if (a >= 65536 && a < RETURN)
		b += ft_putc3(a);
	else if (a == RETURN)
		return (b + 1);
	else if (a == SET_NULL)
		b = 0;
	return (b);
}
