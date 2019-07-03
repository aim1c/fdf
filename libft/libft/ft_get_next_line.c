/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:59:13 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/05 16:08:36 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE 1
#define MAX_FD 4096
#define CHECKEND(car) if (car == 0) return (0);
#define CHECKMEM(rest) if (!rest) rest = ft_strnew(1);

static int	ft_huyak(char **line, char **rest)
{
	char	*tmp;

	CHECKEND((*rest[0]));
	if (ft_strchr(*rest, '\n') != NULL)
	{
		*(ft_strchr(*rest, '\n')) = '\0';
		MERROR((*line = ft_strdup(*rest)));
		MERROR((tmp = ft_strdup(ft_strchr(*rest, '\0') + 1)));
		free(*rest);
		if (tmp)
		{
			MERROR((*rest = ft_strdup(tmp)));
			free(tmp);
		}
	}
	else
	{
		MERROR((*line = ft_strdup(*rest)));
		ft_memdel((void **)rest);
	}
	return (1);
}

int			ft_gnl(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*rest[MAX_FD];
	char		*tmp_rest;
	int			ret;

	if (fd < 0 || !line || fd > MAX_FD || read(fd, buf, 0))
		return (-1);
	CHECKMEM(rest[fd]);
	while (!ft_strchr(rest[fd], '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret == 0)
			break ;
		MERROR((tmp_rest = ft_strjoin(rest[fd], buf)));
		free(rest[fd]);
		MERROR((rest[fd] = ft_strdup(tmp_rest)));
		CHECKMEM(rest[fd]);
		free(tmp_rest);
	}
	return (ft_huyak(line, &rest[fd]));
}
