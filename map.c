/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:20:26 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/25 12:58:26 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

static int		check_map(t_list **lst, int fd)
{
	char	*line;
	t_list	*new;
	int		res;
	int		count;

	count = -1;
	new = 0;
	while ((res = ft_gnl(fd, &line)) > 0)
	{
		if (count == -1)
			count = ft_wordcount(line, ' ');
		if (!new)
		{
			new = ft_lstnew(line, ft_strlen(line) + 1);
			*lst = new;
		}
		else
		{
			new->next = ft_lstnew(line, ft_strlen(line) + 1);
			new = new->next;
		}
	}
	if (res == -1 || count == 0)
		return (0);
	return (1);
}

static int		new_map_fill_param(t_map **map, t_list *lst)
{
	int		x;
	int		y;
	t_list	*l;
	char	**spl;

	y = -1;
	l = lst;
	while (++y < (*map)->y)
	{
		x = -1;
		if ((spl = ft_strsplit(l->content, ' ')) == 0)
			return (0);
		while (++x < (*map)->x)
			(*map)->vectors[y * (*map)->x + x] = init_vect(x, y, spl[x]);
		l = l->next;
	}
	return (1);
}

double		true_gap(int wi, int hi, int xz, int yz)
{
	double count;
	int new_hi;
	int	new_wi;

	new_hi = hi / 2;
	new_wi = wi / 2;
	if ((count = (double)new_wi / xz) < ((double)new_hi / yz))
		return ((double)new_hi / yz);
	else
		return (count);
}

void iso(t_point **ve)
{
	int previous_x;
	int previous_y;
	int z;

	previous_x = (*ve)->x;
	previous_y = (*ve)->y;
	z = (*ve)->z;
	(*ve)->x = (previous_x - previous_y) * cos(0.523599);
	(*ve)->y = -z + (previous_x + previous_y) * sin(0.523599);
}

int	cc(int min, int max, t_map **mp)
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
				v->color = 0X2D279B;
			else if (v->z < max / 2 && v->z > min)
				v->color = 0X831592;
			else if (v->z > max / 2 && v->z < max)
				v->color = 0X128D78;
			else if (v->z == max)
				v->color = 0XDFB11C;
		}
	}
	return (1);
}

static void		min_max(t_map **mp, t_point *ve)
{
	int min;
	int max;
	int y;
	int x;
	int count;

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
			if (ve->y != 0)
				ve->y = ve->y * count - 160;
			else if (ve->y == 0)
				ve->y -= 160;
			if (ve->x != 0)
				ve->x = ve->x * count + 460;
			else
				ve->x += 460;
			if (ve->z > max)
				max = (int)ve->z;
			if (ve->z < min)
				min = (int)ve->z;
			iso(&ve);
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