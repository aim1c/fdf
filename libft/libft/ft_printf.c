/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 23:23:27 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_spec(int a)
{
	if (a == 115 || a == 83)
		return (1);
	else if (a == 99 || a == 67)
		return (1);
	else if (a == 117 || a == 85)
		return (1);
	else if (a == 111 || a == 79)
		return (1);
	else if (a == 100 || a == 105 || a == 68)
		return (1);
	else if (a == 101 || a == 69)
		return (1);
	else if (a == 120 || a == 88)
		return (1);
	else if (a == 112)
		return (1);
	else if (a == 102 || a == 70)
		return (1);
	else if (a == 123)
		return (1);
	return (0);
}

void	ft_get_lenght(t_prin *p)
{
	int cur;

	cur = p->form;
	ft_bzero(p->lenght, 3);
	while (!is_spec(p->format[cur]) && p->format[cur])
	{
		if (p->format[cur] == 'h')
		{
			p->lenght[0] = 'h';
			if (p->format[cur + 1] == 'h')
				p->lenght[1] = 'h';
		}
		else if (p->format[cur] == 'l')
		{
			p->lenght[0] = 'l';
			if (p->format[cur + 1] == 'l')
				p->lenght[1] = 'l';
		}
		else if (p->format[cur] == 'L' || p->format[cur] == 'j'
				|| p->format[cur] == 'z' || p->format[cur] == 'w')
			p->lenght[0] = p->format[cur];
		cur++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_prin	p;
	int		a;

	ft_memset(&p, 0, sizeof(t_prin));
	va_start(p.ap, format);
	p.format = ft_strdup((char *)format);
	while (p.format[p.form] != '\0')
	{
		if (p.format[p.form] == '%')
		{
			ft_get_lenght(&p);
			check_spec(&p);
			free_p(&p);
		}
		else
		{
			ft_prin_c(p.format[p.form]);
			p.form++;
		}
	}
	a = ft_prin_c(RETURN) - 1;
	ft_prin_c(SET_NULL);
	ft_strdel(&p.format);
	va_end(p.ap);
	return (a);
}
