/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:31:28 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/28 13:41:22 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDHT 1920
# define HIGHT 1080

# define COLOR_SCHEME1_1 0X0351C1
# define COLOR_SCHEME1_2 0XD7FFFE
# define COLOR_SCHEME1_3 0X782FEF
# define COLOR_SCHEME1_4 0XFF2970


typedef struct		s_color
{
	int				bottom;
	int				middle_botton;
	int				middle_top;
	int				top;
	struct			s_color		*next;
}					t_color;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	struct s_map	*map;
	struct s_mouse	*mouse;
	double			intense;
	
	void			*img;
	char 			*addr;
	int				endian;
	int				bpp;
	int				size_line;
}					t_fdf;

typedef struct		s_camera
{
	int				step_x;
	int				step_y;
	int				x;
	int				y;
	double				z;
	int color;
}					t_camera;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef	struct		s_map
{
	int				x;
	int				y;
	int				min;
	int				max;
	int				proj;
	struct s_point	**vectors;
	struct s_camera *loc;
	struct s_color	*scheme;
}					t_map;

typedef	struct		s_dxdy
{
	double			dx;
	double			dy;
}					t_d;


int					plot_line(t_camera *v0, t_camera *v1, t_fdf *m);
int					key_press(int code, void *param);
void				render(t_fdf *mlx, t_map *map);
int		get_color(t_camera *current, t_camera *start, t_camera *end, t_d *d);
void				iso(t_point **ve, t_camera *loc);
int					intense(t_map *m);
int					no_intense(t_map *m);
t_fdf				*win_init(char *l);
double				true_gap(int wi, int hi, int xz, int yz);
int					new_map_fill_param(t_map **map, t_list *lst);
int					check_map(t_list **lst, int fd);
int					cc(int min, int max, t_map **mp);

/*
** -------------------------- malloc and init ----------------------------------
*/

t_map				*map_init(int width, int height);
t_point				*init_vect(int x, int y, char *z);

/*
** -------------------------- panic exit ---------------------------------------
*/

int					exit_warning(char *ll);
double				mod(double i);

/*
** -------------------------- main read func() ---------------------------------
*/

int					read_file(t_map **map, int fd);
#endif
