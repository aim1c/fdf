/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:55:30 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/05 14:37:43 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putc1(int c, int fd)
{
	unsigned char	d;
	unsigned char	e;

	e = 128 + (c & 63);
	c = c >> 6;
	d = 128 + 64 + c;
	write(fd, &d, 1);
	write(fd, &e, 1);
}

static void	ft_putc2(int c, int fd)
{
	unsigned char	d;
	unsigned char	e;
	unsigned char	f;

	f = 128 + (c & 63);
	c = c >> 6;
	e = 128 + (c & 63);
	c = c >> 6;
	d = 128 + 64 + 32 + c;
	write(fd, &d, 1);
	write(fd, &e, 1);
	write(fd, &f, 1);
}

static void	ft_putc3(int c, int fd)
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
	write(fd, &q, 1);
	write(fd, &w, 1);
	write(fd, &e, 1);
	write(fd, &r, 1);
}

void		ft_putchar_fd(int a, int fd)
{
	if (a < 128)
		write(fd, &a, 1);
	else if (a >= 128 && a < 2048)
		ft_putc1(a, fd);
	else if (a >= 2048 && a < 65536)
		ft_putc2(a, fd);
	else
		ft_putc3(a, fd);
}
