/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:38:01 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:09 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printani(char *s, t_prin *p, int mi)
{
	t_flags		f;
	int			wi;

	wi = p->width;
	f.len = (int)ft_strlen(s);
	if (p->flag != NULL)
	{
		get_curren_flags_int(&f, p);
		if (f.space && !mi)
			sprint(" ", 1);
		if (f.zero && (mi || f.plus))
			f.plus ? ft_prin_c(43 + (mi * 2)) : sprint("-", 1);
		f.zero ? print_null_sp(wi - ft_strlen(s) -
						((f.space | f.plus) & !mi), '0') : 0;
		if (!f.minus && !f.zero)
			print_null_sp(wi - ft_strlen(s) - ((f.space | f.plus) & !mi), ' ');
		if (!f.zero && f.plus)
			mi ? sprint("-", 1) : sprint("+", 1);
		sprint(&s[mi & (f.plus | f.zero)], ft_strlen(s) - (f.plus & mi));
		if (f.minus)
			print_null_sp(wi - ft_strlen(s) - ((f.space | f.plus) & !mi), ' ');
	}
	else
		sprint(s, ft_strlen(s));
}

static void	ft_printnan(char *mem, char c)
{
	!ft_strcmp(PINF, mem) && c == 102 ? sprint("inf", 3) : 0;
	!ft_strcmp(MINF, mem) && c == 102 ? sprint("-inf", 4) : 0;
	!ft_strcmp(NAAN, mem) && c == 102 ? sprint("nan", 3) : 0;
	!ft_strcmp(PINF, mem) && c == 70 ? sprint("INF", 3) : 0;
	!ft_strcmp(MINF, mem) && c == 70 ? sprint("-INF", 4) : 0;
	!ft_strcmp(NAAN, mem) && c == 70 ? sprint("NAN", 3) : 0;
}

static int	ft_lchecknan(char *mem)
{
	int		plus;
	int		i;
	int		count;

	plus = mem[0] - 48;
	i = 1;
	count = 0;
	while (i < 17)
	{
		count += (mem[i] - 48);
		i++;
	}
	if (count == 16 && mem[i++] == '1')
		count++;
	while (mem[i] && count >= 16)
	{
		mem[i] == '1' ? count = 0 : 0;
		i++;
	}
	if (count == 17 && plus)
		return (3);
	else if (count == 16)
		return (1 + plus);
	else
		return (0);
}

void		fprint(t_prin *p)
{
	double		tmp;
	char		*res;
	char		*mem;
	int			minus;

	tim(p);
	(p->strike == -1) ? p->strike = 6 : 0;
	if (p->lenght[0] == 'L')
	{
		flprint(p);
		return ;
	}
	tmp = va_arg(p->ap, double);
	mem = ft_get_membit(&tmp, sizeof(tmp));
	if (!ft_strcmp(PINF, mem) || !ft_strcmp(MINF, mem) || !ft_strcmp(NAAN, mem))
	{
		ft_printnan(mem, p->spec);
		ft_strdel(&mem);
		return ;
	}
	ft_strdel(&mem);
	res = ft_getdbl(tmp, p->strike);
	minus = (res[0] == '-') ? 1 : 0;
	ft_printani(res, p, minus);
	ft_strdel(&res);
}

void		flprint(t_prin *p)
{
	long double	tmp;
	char		*res;
	char		*mem;
	int			minus;

	tmp = va_arg(p->ap, long double);
	(p->strike == -1) ? p->strike = 6 : 0;
	mem = ft_get_membit(&tmp, 10);
	if (ft_lchecknan(mem))
	{
		ft_lchecknan(mem) == 2 ? sprint("-", 1) : 0;
		ft_lchecknan(mem) != 3 && p->spec == 102 ? sprint("inf", 3) : 0;
		ft_lchecknan(mem) != 3 && p->spec == 102 ? sprint("INF", 3) : 0;
		ft_lchecknan(mem) == 3 && p->spec == 102 ? sprint("nan", 3) : 0;
		ft_lchecknan(mem) == 3 && p->spec == 70 ? sprint("NAN", 3) : 0;
		ft_strdel(&mem);
		return ;
	}
	ft_strdel(&mem);
	res = ft_get_ldbl(tmp, p->strike);
	minus = (res[0] == '-') ? 1 : 0;
	ft_printani(res, p, minus);
	ft_strdel(&res);
}
