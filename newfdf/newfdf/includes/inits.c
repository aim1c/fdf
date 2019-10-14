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

typedef struct	s_all
{
	
}				t_all;


t_color	*colors_init() {
	t_color		*c1;
	t_color		*c2;
	t_color		*c3;
	
	c1 = (t_color *)malloc(sizeof(t_color));
	c2 = (t_color *)malloc(sizeof(t_color));
	c3 = (t_color *)malloc(sizeof(t_color));
	
	c1->bottom = 0X4512AE;
	c1->middle_botton = 0X8506A9;
	c1->middle_top = 0XE5FB00;
	c1->top = 0XFFDD00;

	c2->bottom = 0X3F0B81;
	c2->middle_botton = 0XCA1A8E;
	c2->middle_top = 0X7AB1FF;
	c2->top = 0XF1F2F2;

	c3->bottom = 0XBDCCFF;
	c3->middle_botton = 0X7AB1FF;
	c3->middle_top = 0XFFEB7F;
	c3->top = 0XF85C50;
	
	c1->next = c2;
	c2->next = c3;
	c3->next = c1;
	
	return c1;
}


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
	map->proj = 1;
	vector = malloc(sizeof(t_point *) * width * height);
	map->scheme = colors_init();
	map->loc = malloc(sizeof(t_camera));
	map->loc->x = 0;
	map->loc->y = 0;
	map->loc->z = 0.1;
	map->loc->step_x = 0;
	map->loc->step_y = 0;
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
	m->bpp = 4;
	m->endian = 0;
	m->size_line = WIDHT;
	ft_strdel(&ll);
	return (m);
}

t_point		*init_vect(int x, int y, char *z)
{
	t_point		*vect;

	vect = ft_memalloc(sizeof(t_point));
	vect->x = (double)x;
	vect->y = (double)y;
	vect->z = (double)ft_atoi(z);
	vect->color = 0xFFFFFF;
	return (vect);
}
