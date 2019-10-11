/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:20:26 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/28 12:53:10 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

int				cc(int min, int max, t_map **mp)
{
	int		y;
	int		x;
	t_point *v;

	y = -1;
	while (++y < (*mp)->y)
	{
		x = -1;
		while (++x < (*mp)->x)
		{
			v = (*mp)->vectors[y * (*mp)->x + x];
			if (v->z == min)
				v->color = (*mp)->scheme->bottom;
			else if (v->z < max / 2 && v->z > min)
				v->color = (*mp)->scheme->middle_botton;
			else if (v->z > max / 2 && v->z < max)
				v->color = (*mp)->scheme->middle_top;
			else if (v->z == max)
				v->color = (*mp)->scheme->top;
		}
	}
	return (1);
}

static void		f(t_point *ve, int count)
{
	if (ve->y != 0)
		ve->y = ve->y * count - 160;
	else if (ve->y == 0)
		ve->y -= 160;
	if (ve->x != 0)
		ve->x = ve->x * count + 460;
	else
		ve->x += 460;
}

static void		min2(t_point *ve, int *min, int *max)
{
	if (ve->z > *max)
		*max = (int)ve->z;
	if (ve->z < *min)
		*min = (int)ve->z;
}

static void		min_max(t_map **mp, t_point *ve)
{
	int y;
	int x;
	int count;
	int min;
	int max;

	min = 0X7FFFFFFF;
	max = -2147483648;
	y = -1;
	count = (double)true_gap(WIDHT, HIGHT, (*mp)->x, (*mp)->y);
	while (++y < (*mp)->y)
	{
		x = -1;
		while (++x < (*mp)->x)
		{
			ve = (*mp)->vectors[y * (*mp)->x + x];
			f(ve, count);
			min2(ve, &min, &max);
			if ((*mp)->proj == 1) {
				iso(&ve);
			}
		}
	}
	(*mp)->min = min;
	(*mp)->max = max;
	cc(min, max, mp);
}

int				read_file(t_map **map, int fd)
{
	t_list	*lst;

	if (!check_map(&lst, fd))
		return (0);
	*map = map_init(ft_wordcount(lst->content, ' '), ft_lstsize(lst));
	if (!new_map_fill_param(map, lst))
		return (0);
	min_max(map, NULL);
	return (1);
}
