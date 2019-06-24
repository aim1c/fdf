/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:16:24 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_get_ures(t_prin *p)
{
	size_t res;

	res = va_arg(p->ap, size_t);
	if (p->lenght[0] == 'l' || p->lenght[0] == 'j'
					|| p->spec == 85 || p->spec == 79)
	{
		if (p->lenght[1] == 'l' || p->lenght[0] == 'j'
					|| p->spec == 85 || p->spec == 79)
			res = (size_t)res;
		else
			res = (unsigned long int)res;
	}
	else if (p->lenght[0] == 'h')
	{
		if (p->lenght[1] == 'h')
			res = (unsigned char)res;
		else
			res = (unsigned short int)res;
	}
	else if (p->lenght[0] == 0)
		res = (unsigned int)res;
	p->lenght[0] == 'z' ? res = (ssize_t)res : 0;
	return (res);
}

static	void	ft_write(char *tmp, int sp, int wi, char *flag)
{
	int i;

	i = (int)ft_strlen(tmp);
	if (ft_flag(flag, "0") && sp == -1)
	{
		wi -= (int)ft_strlen(tmp);
		print_null_sp(wi, '0');
		ft_putstr_rev(tmp, i);
	}
	else if (ft_flag(flag, "-"))
	{
		ft_flag(flag, "#") && !(tmp[0] == '0' && i == 1) ?
									(wi -= i) : (wi -= i);
		ft_putstr_rev(tmp, i);
		print_null_sp(wi, ' ');
	}
	else
	{
		ft_flag(flag, "#") && sp == -1 ? (wi -= i + 1) && (write(1, "0", 1))
																: (wi -= i);
		print_null_sp(wi, ' ');
		ft_putstr_rev(tmp, i);
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

void			uprint(t_prin *p)
{
	size_t			nbr;
	char			tmp[25];
	int				i;

	i = 0;
	nbr = ft_get_ures(p);
	ft_bzero(tmp, 25);
	tim(p);
	while (42)
	{
		tmp[i] = nbr % 10 + '0';
		nbr /= 10;
		if (nbr <= 0)
			break ;
		i++;
	}
	if (p->strike > (int)ft_strlen(tmp))
		mmm(tmp, p->strike, p->width, p->flag);
	else if (!p->strike && ft_strlen(tmp) == 1 && tmp[0] == 48 && !p->width)
		return ;
	else
		ft_write(tmp, p->strike, p->width, p->flag);
}
