/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:25:35 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/04 20:49:10 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putc1(int c)
{
	unsigned char	d;
	unsigned char	e;

	e = 128 + (c & 63);
	c = c >> 6;
	d = 128 + 64 + c;
	write(1, &d, 1);
	write(1, &e, 1);
}

static void	ft_putc2(int c)
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
}

static void	ft_putc3(int c)
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
}

void		ft_putchar(int a)
{
	if (a < 128)
	{
		write(1, &a, 1);
	}
	else if (a >= 128 && a < 2048)
		ft_putc1(a);
	else if (a >= 2048 && a < 65536)
		ft_putc2(a);
	else
		ft_putc3(a);
}
