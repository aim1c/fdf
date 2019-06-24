/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:27:14 by marvin            #+#    #+#             */
/*   Updated: 2019/05/29 00:58:09 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(char *dest, char *flags)
{
	int		res;
	size_t	len;

	res = 0;
	len = ft_strlen(flags);
	if (dest == NULL)
		return (0);
	while (*dest != '\0' && *flags != '\0')
	{
		if (*dest == *flags && len == 1)
			return (1);
		if (*dest == *flags && len > 1)
		{
			res++;
			flags++;
		}
		dest++;
	}
	if (res == (int)len)
		return (1);
	return (0);
}

void	flags(t_prin *p)
{
	int cur;
	int i;

	i = 0;
	cur = p->form + 1;
	while ((!ft_isdigit(p->format[cur]) || p->format[cur] == '0')
				&& (p->format[cur] != p->spec) && p->format[cur] != '.'
				&& p->format[cur] != 'l' && p->format[cur] != 'h')
	{
		i++;
		cur++;
	}
	if (i > 0)
	{
		p->flag = ft_memalloc((size_t)i + 1);
		while (--i >= 0)
		{
			p->flag[i] = p->format[cur - 1];
			cur--;
		}
	}
}

void	tim(t_prin *p)
{
	int cur;

	cur = p->form + 1;
	p->strike = -1;
	flags(p);
	while (p->format[cur] != p->spec)
	{
		if (ft_isdigit(p->format[cur]) && (p->format[cur] != '0'))
		{
			p->width = ft_atoi(&p->format[cur]);
			while (p->format[cur] != '.' && p->format[cur] != p->spec)
				cur++;
		}
		if (p->format[cur] == '.')
		{
			(p->strike = ft_atoi(&p->format[cur + 1]));
			while (p->format[cur] != p->spec)
				cur++;
		}
		(p->format[cur] != p->spec) ? cur++ : 0;
	}
	p->form = cur + 1;
}

void	what_do(int c, t_prin *p)
{
	(c == 123) ? getcolor(p) : 0;
	(c == 115 && (p->lenght[0] == 'w' || p->lenght[0] == 'l'))
							? ssdprint(p) : 0;
	(c == 115 && !(p->lenght[0] == 'w' || p->lenght[0] == 'l'))
							? sdprint(p) : 0;
	(c == 83) ? ssdprint(p) : 0;
	(c == 99 || c == 67) ? cprint(p) : 0;
	(c == 117 || c == 85) ? uprint(p) : 0;
	(c == 111 || c == 79) ? oprint(p) : 0;
	(c == 101 || c == 69) ? eprint(p) : 0;
	(c == 120 || c == 88) ? xprint(p) : 0;
	(c == 100 || c == 105 || c == 68) ? dprint(p) : 0;
	(c == 112) ? pprint(p) : 0;
	(c == 102) || (c == 70) ? fprint(p) : 0;
	(c == 37 || c == 0) ? piskaprint(p) : 0;
}

void	check_spec(t_prin *p)
{
	int		cur;
	int		perc;

	cur = p->form;
	perc = 0;
	while (42)
	{
		if (p->format[cur] == 37)
			perc += 1;
		if ((p->format[cur] == 37 && perc == 2) || p->format[cur] == '\0')
		{
			p->spec = p->format[cur];
			what_do(p->format[cur], p);
			break ;
		}
		if (is_spec(p->format[cur]))
		{
			p->spec = p->format[cur];
			what_do(p->format[cur], p);
			break ;
		}
		cur++;
	}
}
