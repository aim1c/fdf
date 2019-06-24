/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:09:31 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/24 14:15:59 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		intense(t_map *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
		{
			t_point *ve = m->vectors[y * m->x + x];
			ve->x = ve->x * 2 - 400;
			ve->y = ve->y * 2 - 100;
		}
	}
	return (1);
}

int		no_intense(t_map *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
		{
			t_point *ve = m->vectors[y * m->x + x];
			ve->x = ve->x / 2 + 200;
			ve->y = ve->y / 2 + 50;
		}
	}
	return (1);
}
