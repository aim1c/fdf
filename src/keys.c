/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:34:02 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/28 12:42:36 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define STEP 20

int		move_r(t_map *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
			m->vectors[y * m->x + x]->x += STEP;
	}
	return (1);
}

int		move_d(t_map *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
			m->vectors[y * m->x + x]->y += STEP;
	}
	return (1);
}

int		move_l(t_map *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
			m->vectors[y * m->x + x]->x -= STEP;
	}
	return (1);
}

int		move_u(t_map *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
			m->vectors[y * m->x + x]->y -= STEP;
	}
	return (1);
}

int		key_press(int code, void *param)
{
	t_fdf *mlx;

	mlx = (t_fdf *)param;
	if (code == 53)
		exit(EXIT_SUCCESS);
	if (code == 124 || code == 2)
		move_l(mlx->map);
	if (code == 125 || code == 1)
		move_u(mlx->map);
	if (code == 123 || code == 0)
		move_r(mlx->map);
	if (code == 126 || code == 13)
		move_d(mlx->map);
	if (code == 24)
		intense(mlx->map);
	if (code == 27)
		no_intense(mlx->map);
	render(mlx, mlx->map);
	return (1);
}
