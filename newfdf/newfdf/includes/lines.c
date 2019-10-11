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


void		pitpxl(int x, int y, int color, t_fdf *mlx) {
	
	char *addr = mlx->addr;
	int i = (x * mlx->bpp / 8) + (y * mlx->size_line);
	if (x < WIDHT && y < HIGHT && x >= 0 && y >= 0) {
	
	addr[i] = color;
	addr[++i] = color >> 8;
	addr[++i] = color >> 16;
	addr[++i] = 0;
	}
}


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
	double	dd;

	d.dx = v1->x - v0->x;
	d.dy = v1->y - v0->y;
	yi = 1;
	if (d.dy < 0)
		ret(&yi, &d, 0);
	c.x = v0->x - 1;
	dd = 2 * d.dy - d.dx;
	c.y = v0->y;
	while (++c.x < v1->x)
	{
		pitpxl(c.x, c.y, get_color(&c, v0, v1, &d), m);
		if (dd > 0)
		{
			c.y = c.y + yi;
			dd = dd - 2 * d.dx;
		}
		dd = dd + 2 * d.dy;
	}
	return (1);
}

int			plot_line_high(t_point *v0, t_point *v1, t_fdf *m)
{
	t_d		d;
	t_point	c;
	int		xi;
	int		dd;

	d.dx = v1->x - v0->x;
	d.dy = v1->y - v0->y;
	xi = 1;
	if (d.dx < 0)
		ret(&xi, &d, 1);
	dd = 2 * d.dx - d.dy;
	c.x = v0->x;
	c.y = v0->y - 1;
	while (++c.y < v1->y)
	{
		pitpxl(c.x, c.y, get_color(&c, v0, v1, &d), m);
		if (dd > 0)
		{
			c.x = c.x + xi;
			dd = dd - 2 * d.dy;
		}
		dd = dd + 2 * d.dx;
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

void		fill(t_fdf *mlx) {
	
	char *addr = mlx->addr;
	ft_bzero(addr, (size_t)(WIDHT * HIGHT * mlx->bpp / 8));
	int *add = (int *)mlx->addr;
	
	int i = 0;
	
	while (i < WIDHT * HIGHT) {
		add[i] = 0x222222;
		i++;
	}
}

void		render(t_fdf *mlx, t_map *map)
{
	int x;
	int y;

	y = -1;
	x = -1;

	fill(mlx);
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->proj == 1) {
				iso(&map->vectors[y * map->x + x]);
			}
			if (x + 1 < map->x)
				plot_line(map->vectors[y * map->x + x],
						map->vectors[y * map->x + x + 1], mlx);
			if (y + 1 < map->y)
				plot_line(map->vectors[y * map->x + x],
						map->vectors[(y + 1) * map->x + x], mlx);
		}
	}
	printf("%f\n", map->vectors[0]->x);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
