/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 03:08:49 by marvin            #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			sprint(char *tmp, int sp)
{
	while (*tmp && sp > 0)
	{
		ft_prin_c(*tmp);
		tmp++;
		sp--;
	}
}

void			ssprint(int *tmp, int sp)
{
	while (*tmp && sp > 0)
	{
		ft_prin_c(*tmp);
		tmp++;
		sp--;
	}
}

static size_t	ft_sstrlen(int const *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		c += (*s < 128) ? 1 : 0;
		c += (*s >= 128 && *s < 2048) ? 2 : 0;
		c += (*s >= 2048 && *s < 65536) ? 3 : 0;
		c += (*s >= 65536 && *s < RETURN) ? 4 : 0;
		s++;
	}
	return (c);
}

void			sdprint(t_prin *p)
{
	char	*tmp;
	int		len;

	tim(p);
	tmp = va_arg(p->ap, char *);
	if (!tmp)
	{
		sprint("(null)", 6);
		return ;
	}
	len = (int)ft_strlen(tmp);
	p->strike < len && p->strike != -1 ? (len = p->strike) : (len);
	if (ft_flag(p->flag, "-"))
	{
		sprint(tmp, len);
		if (p->width > len)
			print_null_sp(p->width - len, ' ');
	}
	else
	{
		if (p->width > len)
			print_null_sp(p->width - len, ' ');
		sprint(tmp, len);
	}
}

void			ssdprint(t_prin *p)
{
	int		*tmp;
	int		len;

	tim(p);
	tmp = va_arg(p->ap, int *);
	if (tmp == NULL)
	{
		sprint("(null)", 6);
		return ;
	}
	len = ft_sstrlen(tmp);
	p->strike < len && p->strike != -1 ? (len = p->strike - 1) : (len);
	if (ft_flag(p->flag, "-"))
	{
		ssprint(tmp, len);
		if (p->width > len)
			print_null_sp(p->width - len, ' ');
	}
	else
	{
		if (p->width > len)
			print_null_sp(p->width - len, ' ');
		ssprint(tmp, len);
	}
}
