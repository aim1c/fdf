/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:47:15 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:09 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_currentcolor(t_prin *p)
{
	char	*tmp;
	char	*color;
	int		i;

	tmp = ft_strchr(&p->format[p->form], '{') + 1;
	color = ft_strnew(8);
	ft_bzero(color, 8);
	i = 0;
	while (tmp[i] != '}')
	{
		color[i] = tmp[i];
		i++;
	}
	return (color);
}

void		getcolor(t_prin *p)
{
	char	*tmp;
	int		curr;

	tmp = ft_currentcolor(p);
	ft_strstr(tmp, "black") ? write(1, BLACK, 7) : 0;
	ft_strstr(tmp, "red") ? write(1, RED, 7) : 0;
	ft_strstr(tmp, "green") ? write(1, GREEN, 7) : 0;
	ft_strstr(tmp, "yellow") ? write(1, YELLOW, 7) : 0;
	ft_strstr(tmp, "blue") ? write(1, BLUE, 7) : 0;
	ft_strstr(tmp, "madjenta") ? write(1, MADJENTA, 7) : 0;
	ft_strstr(tmp, "cian") ? write(1, CIAN, 7) : 0;
	ft_strstr(tmp, "white") ? write(1, WHITE, 7) : 0;
	while (p->format[p->form] != '}')
		p->form++;
	curr = p->form;
	while (!is_spec(p->format[curr]))
		curr++;
	p->spec = p->format[curr];
	what_do(p->spec, p);
	write(1, RESET, 4);
	ft_strdel(&tmp);
}
