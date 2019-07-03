/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:21:14 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/28 12:41:16 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*map_init(int width, int height)
{
	t_map		*map;
	t_point		**vector;

	map = 0;
	map = (t_map *)malloc(sizeof(t_map) + 1);
	if (map == 0)
		exit_warning("no malloc \n map = (t_map *)malloc(sizeof(t_map) + 1);");
	map->y = height;
	map->x = width;
	vector = malloc(sizeof(t_point *) * width * height);
	if (vector == 0)
		exit_warning("vector = null");
	map->vectors = vector;
	return (map);
}

t_fdf		*win_init(char *l)
{
	t_fdf	*m;
	char	*ll;

	ll = ft_strjoin("FDF -", l);
	m = (t_fdf *)malloc(sizeof(t_fdf) + 1);
	if (m == 0)
		return (0);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIDHT, HIGHT, ll);
	ft_strdel(&ll);
	return (m);
}

t_point		*init_vect(int x, int y, char *z)
{
	t_point		*vect;

	vect = ft_memalloc(sizeof(t_point));
	vect->x = (double)x;
	vect->y = (double)y;
	vect->z = (double)ft_atoi(z) * 10;
	vect->color = 0xFFFFFF;
	return (vect);
}
