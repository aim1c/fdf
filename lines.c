/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:08:35 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/24 16:16:07 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ret(int *a, t_d *b, int s)
{
	if (s == 0)
		b->dy *= -1;
	if (s == 1)
		b->dx *= -1;
	*a = -1;
}

int			plot_line_low(t_point *v0, t_point *v1, t_fdf *m)
{
	t_d		d;
	int		yi;
	t_point	c;
	double	D;

	d.dx = v1->x - v0->x;
	d.dy = v1->y - v0->y;
	yi = 1;
	if (d.dy < 0)
		ret(&yi, &d, 0);
	c.x = v0->x - 1;
	D = 2 * d.dy - d.dx;
	c.y = v0->y;
	while (++c.x < v1->x)
	{
		mlx_pixel_put(m->mlx, m->win, c.x, c.y, get_color(&c, v0, v1, &d));
		if (D > 0)
		{
			c.y = c.y + yi;
			D = D - 2 * d.dx;
		}
		D = D + 2 * d.dy;
	}
	return (1);
}

int			plot_line_high(t_point *v0, t_point *v1, t_fdf *m)
{
	t_d		d;
	t_point	c;
	int		xi;
	int		D;

	d.dx = v1->x - v0->x;
	d.dy = v1->y - v0->y;
	xi = 1;
	if (d.dx < 0)
		ret(&xi, &d, 1);
	D = 2 * d.dx - d.dy;
	c.x = v0->x;
	c.y = v0->y - 1;
	while (++c.y < v1->y)
	{
		mlx_pixel_put(m->mlx, m->win, c.x, c.y, get_color(&c, v0, v1, &d));
		if (D > 0)
		{
			c.x = c.x + xi;
			D = D - 2 * d.dy;
		}
		D = D + 2 * d.dx;
	}
	return (1);
}

int			plot_line(t_point *v0, t_point *v1, t_fdf *m)
{
	if (mod(v1->y - v0->y) < mod(v1->x - v0->x))
	{
		if (v0->x > v1->x)
			plot_line_low(v1, v0, m);
		else
			plot_line_low(v0, v1, m);
	}
	else
	{
		if (v0->y > v1->y)
			plot_line_high(v1, v0, m);
		else
			plot_line_high(v0, v1, m);
	}
	return (1);
}

void		render(t_fdf *mlx, t_map *map)
{
	int x;
	int y;

	y = -1;
	x = -1;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (x + 1 < map->x)
				plot_line(map->vectors[y * map->x + x],
						  map->vectors[y * map->x + x + 1], mlx);
			if (y + 1 < map->y)
				plot_line(map->vectors[y * map->x + x],
						  map->vectors[(y + 1) * map->x + x], mlx);
		}
	}
}