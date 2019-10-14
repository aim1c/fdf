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

int		move_r(t_camera *m)
{
	m->step_x -= STEP;
	return (1);
}

int		move_d(t_camera *m)
{
	m->step_y -= STEP;
	return (1);
}

int		move_l(t_camera *m)
{
	m->step_x += STEP;
	return (1);
}

int		move_u(t_camera *m)
{
	m->step_y += STEP;
	return (1);
}

int		key_press(int code, void *param)
{
	t_fdf *mlx;

	mlx = (t_fdf *)param;
	if (code == 53)
		exit(EXIT_SUCCESS);
	if (code == 124 || code == 2)
		move_l(mlx->map->loc);
	if (code == 125 || code == 1)
		move_u(mlx->map->loc);
	if (code == 123 || code == 0)
		move_r(mlx->map->loc);
	if (code == 126 || code == 13)
		move_d(mlx->map->loc);
	if (code == 24)
		intense(mlx->map);
	if (code == 27)
		no_intense(mlx->map);
	if (code == 7) {
		mlx->map->scheme = mlx->map->scheme->next;
		cc(mlx->map->min, mlx->map->max, &mlx->map);
	}
	if (code == 34) {
		mlx->map->proj = 1;
	}
	if (code == 35) {
		mlx->map->proj = 2;
	}
	if (code == 6)
		mlx->map->loc->z -= 0.1;
	if (code == 8)
		mlx->map->loc->z += 0.1;
	render(mlx, mlx->map);
	return (1);
}
