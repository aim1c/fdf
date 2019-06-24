/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:31:28 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/25 12:50:16 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef fdf_h
#define fdf_h

#include <stdio.h>
#include "mlx.h"
#include "libft/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

# define WIDHT 1280
# define HIGHT 720

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	struct s_map	*map;
	struct s_mouse	*mouse;
	double			intense;
}					t_fdf;

typedef struct		s_map
{
	int				x;
	int				y;
	int				min;
	int				max;
	struct			s_point **vectors;
}					t_map;

typedef struct 		s_dxdy
{
	double 			dx;
	double			dy;
}					t_d;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

int					plot_line(t_point *v0, t_point *v1, t_fdf *m);
int					key_press(int code, void *param);
void				render(t_fdf *mlx, t_map *map);
int					get_color(t_point *current, t_point *start,
							t_point *end, t_d *d);
void				iso(t_point **ve);
int					intense(t_map *m);
int					no_intense(t_map *m);
t_fdf				*win_init(char *l);

/*
** -------------------------- malloc and init ----------------------------------
*/

t_map	*map_init(int width, int height);
t_point	*init_vect(int x, int y, char *z);

/*
** -------------------------- panic exit ---------------------------------------
*/

int		exit_warning(char *ll);
double		mod(double i);

/*
** -------------------------- main read func() ---------------------------------
*/

int		read_file(t_map **map, int fd);
#endif /* fdf_h */
