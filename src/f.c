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

int				check_map(t_list **lst, int fd)
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

int				new_map_fill_param(t_map **map, t_list *lst)
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

double			true_gap(int wi, int hi, int xz, int yz)
{
	double		count;
	int			new_hi;
	int			new_wi;

	new_hi = hi / 2;
	new_wi = wi / 2;
	if ((count = (double)new_wi / xz) < ((double)new_hi / yz))
		return ((double)new_hi / yz);
	else
		return (count);
}

void			iso(t_point **ve)
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
