/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 04:18:28 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t			ft_get_res(t_prin *p)
{
	int64_t res;

	res = va_arg(p->ap, int64_t);
	if (p->lenght[0] == 'l' || p->lenght[0] == 'j'
					|| p->spec == 'D' || p->lenght[0] == 'z')
	{
		if (p->lenght[1] == 'l' || p->lenght[0] == 'j')
			res = (long long)res;
		else
			res = (long int)res;
		p->lenght[0] == 'z' ? res = (ssize_t)res : 0;
		res == INT64_MIN ? p->lenght[1] = 'M' : 0;
	}
	else if (p->lenght[0] == 'h')
	{
		if (p->lenght[1] == 'h')
			res = (char)res;
		else
			res = (short int)res;
	}
	else if (p->lenght[0] == 0)
		res = (int)res;
	return (res);
}

static	void	ft_write(char *tmp, int sp, int wi, char *flag)
{
	int i;

	i = (int)ft_strlen(tmp);
	if (ft_flag(flag, "-"))
	{
		ft_flag(flag, "#") && !(tmp[0] == '0' && i == 1) && sp == -1
						? (wi -= i + 1) : (wi -= i);
		ft_flag(flag, "#") && !(tmp[0] == '0' && i == 1) && sp == -1
						? sprint("0", 1) : 0;
		(tmp[0] == '-') ? print_null_sp(1, ' ') : ft_putstr_rev(tmp, i);
		print_null_sp(wi, ' ');
	}
	else if (ft_flag(flag, "0") && sp == -1)
	{
		print_null_sp(wi - i, '0');
		(tmp[0] == '-') ? print_null_sp(1, ' ') : ft_putstr_rev(tmp, i);
	}
	else
	{
		ft_flag(flag, "#") ? wi -= ft_strlen(tmp) + 1 : (wi -= ft_strlen(tmp));
		print_null_sp(wi, ' ');
		ft_flag(flag, "#") && !(sp == -1 && tmp[0] == 48) ? sprint("0", 1) : 0;
		(tmp[0] == '-') && !ft_flag(flag, "#")
							? print_null_sp(1, ' ') : ft_putstr_rev(tmp, i);
	}
}

static	void	mmm(char *tmp, int sp, int wi, char *flag)
{
	int		i;
	char	*tmm;

	i = 0;
	tmm = (char *)malloc(sizeof(char) * sp + 1);
	tmm == NULL ? exit(EXIT_FAILURE) : 0;
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
	ft_write(tmm, i, wi, flag);
	ft_strdel(&tmm);
}

void			oprint(t_prin *p)
{
	size_t	number;
	int		i;
	char	tmp[25];

	i = 0;
	ft_bzero(tmp, 25);
	number = ft_get_ures(p);
	tim(p);
	while (42)
	{
		tmp[i] = (number % 8) + '0';
		number /= 8;
		if (number <= 0)
			break ;
		i++;
	}
	if (p->strike > (int)ft_strlen(tmp))
		mmm(tmp, p->strike, p->width, p->flag);
	else if (!p->strike && ft_strlen(tmp) == 1 && tmp[0] == 48 && !p->width)
		ft_flag(p->flag, "#") ? sprint("0", 1) : 0;
	else if (!p->strike && ft_strlen(tmp) == 1 && tmp[0] == 48)
		ft_write("-", i, p->width, p->flag);
	else
		ft_write(tmp, p->strike, p->width, p->flag);
}
