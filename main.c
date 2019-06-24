/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:31:28 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/25 12:49:47 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_warning(char *ll)
{
	ft_printf("%s\n",ll);
	exit(EXIT_FAILURE);
}

int		main(int ac, char *av[])
{
	t_fdf	*mlx;
	t_map	*map;
	int		fd;

	map = 0;
	mlx = 0;
	if (ac != 2)
		exit_warning("no data, bro ¯\\_(ツ)_/¯");
	fd = open(av[1], O_RDONLY);
	if ((mlx = win_init(av[1])) == 0)
		exit_warning("pochel nahui ¯\\_(ツ)_/¯");
	if (fd < 0 || !read_file(&map, fd))
		exit_warning("bad fd bro ¯\\_(ツ)_/¯");
	mlx->map = map;
	render(mlx, map);
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_loop(mlx->mlx);
}