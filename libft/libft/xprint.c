/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:54:26 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_a_null(const char *tmp, int i)
{
	int b;

	b = i;
	while (i >= 0)
	{
		if (tmp[i] == '\0' || tmp[i] == '0')
			b--;
		i--;
	}
	if (b == i)
		return (1);
	return (0);
}

static	void	ft_write(char *tmp, int sp, int wi, char *flag)
{
	int i;

	i = (int)ft_strlen(tmp);
	if (ft_flag(flag, "0") && sp == -1)
	{
		ft_memset(&wi, wi - ft_strlen(tmp), 4) ? print_null_sp(wi, '0') : 0;
		ft_putstr_rev(tmp, i);
	}
	else if (ft_flag(flag, "-"))
	{
		ft_flag(flag, "#") && !ft_a_null(tmp, i) ? (wi -= i + 2) : (wi -= i);
		ft_flag(flag, "#") && !ft_a_null(tmp, i) && (tmp[0] != '-')
								? sprint("0x", 2) : 0;
		ft_putstr_rev(tmp, i);
		print_null_sp(wi, ' ');
	}
	else
	{
		ft_flag(flag, "#") && !ft_a_null(tmp, i) ? (wi -= i + 2) : (wi -= i);
		!ft_flag(flag, "0") ? print_null_sp(wi, ' ') : 0;
		ft_flag(flag, "#") && !ft_a_null(tmp, i) && (tmp[0] != '-')
								? (sprint("0x", 2)) : 0;
		ft_flag(flag, "0") ? print_null_sp(wi, '0') : 0;
		(tmp[0] == '-') ? print_null_sp(1, ' ') : ft_putstr_rev(tmp, i);
	}
}

static	void	ft_wx(char *tmp, int sp, int wi, char *flag)
{
	int i;

	i = (int)ft_strlen(tmp);
	if (ft_flag(flag, "0") && sp == -1)
	{
		ft_memset(&wi, wi - ft_strlen(tmp), 4) ? print_null_sp(wi, '0') : 0;
		ft_putstr_rev(tmp, i);
	}
	else if (ft_flag(flag, "-"))
	{
		ft_flag(flag, "#") && !ft_a_null(tmp, i) ? (wi -= i + 2) : (wi -= i);
		ft_flag(flag, "#") && !ft_a_null(tmp, i) && (tmp[0] != '-')
								? sprint("0X", 2) : 0;
		ft_putstr_rev(tmp, i);
		print_null_sp(wi, ' ');
	}
	else
	{
		ft_flag(flag, "#") && !ft_a_null(tmp, i) ? (wi -= i + 2) : (wi -= i);
		!ft_flag(flag, "0") ? print_null_sp(wi, ' ') : 0;
		ft_flag(flag, "#") && !ft_a_null(tmp, i) && (tmp[0] != '-')
								? (sprint("0X", 2)) : 0;
		ft_flag(flag, "0") ? print_null_sp(wi, '0') : 0;
		(tmp[0] == '-') ? print_null_sp(1, ' ') : ft_putstr_rev(tmp, i);
	}
}

static void		print_only_zero(const char *tmp, int sp, int wi, char *flag)
{
	char	*tmm;
	int		i;

	tmm = (char *)malloc(sizeof(char) * sp + 1);
	tmm == NULL ? exit(EXIT_FAILURE) : 0;
	i = 0;
	ft_bzero(tmm, (size_t)sp + 1);
	while (tmp[i] != 0)
	{
		tmm[i] = tmp[i];
		i++;
		sp--;
	}
	while (sp > 0)
	{
		tmm[i] = '0';
		i++;
		sp--;
	}
	tmm[i++] = '\0';
	ft_write(tmm, sp, wi, flag);
	ft_strdel(&tmm);
}

void			xprint(t_prin *p)
{
	size_t			number;
	char			tmp[30];
	int				i;

	number = ft_get_ures(p);
	i = 0;
	tim(p);
	ft_bzero(tmp, 30);
	while (42)
	{
		tmp[i] = table_hex((number % 16), p->spec);
		number /= 16;
		if (++i && number <= 0)
			break ;
	}
	if (p->strike > (i - 1))
		print_only_zero(tmp, p->strike, p->width, p->flag);
	else if (!p->strike && ft_strlen(tmp) == 1 && tmp[0] == 48 && !p->width)
		return ;
	else if (!p->strike && ft_strlen(tmp) == 1 && tmp[0] == 48)
		p->spec == 'X' ? ft_wx("-", (i - 1), p->width, p->flag)
				: ft_write("-", (i - 1), p->width, p->flag);
	else
		p->spec == 'X' ? ft_wx(tmp, (i - 1), p->width, p->flag)
				: ft_write(tmp, (i - 1), p->width, p->flag);
}
