/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:05:44 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/28 13:56:10 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_point *current, t_point *start, t_point *end, t_d *d)
{
	int		red;
	int		green;
	int		blue;
	double	percen;

	if (current->color == end->color)
		return (current->color);
	if (d->dx > d->dy)
		percen = percent(start->x, end->x, current->x);
	else
		percen = percent(start->y, end->y, current->y);
	red = get_light((start->color >> 16) & 0xFF,
				(end->color >> 16) & 0xFF, percen);
	green = get_light((start->color >> 8) & 0xFF,
				(end->color >> 8) & 0xFF, percen);
	blue = get_light(start->color & 0xFF, end->color & 0xFF, percen);
	return ((red << 16) | (green << 8) | blue);
}
