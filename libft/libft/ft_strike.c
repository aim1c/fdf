/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strike.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 07:10:43 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putzero(char **lowres, int strike)
{
	int		n;
	char	*zeroes;
	char	*tmp;

	n = strike - ft_strlen(*lowres);
	zeroes = ft_strnew(n);
	ft_memset(zeroes, 48, n);
	tmp = ft_strjoin(*lowres, zeroes);
	ft_strdel(lowres);
	ft_strdel(&zeroes);
	*lowres = ft_strdup(tmp);
	ft_strdel(&tmp);
}

int				ft_round_off(char *lowres, int strike)
{
	int	n;

	n = ft_strlen(lowres) + 1;
	while (--n >= 2 && (n > strike || ft_strchr(lowres, 58)))
	{
		if (n > 2 && lowres[n - 2] == 58)
		{
			lowres[n - 2] = 48;
			lowres[n - 3]++;
		}
		(lowres[n - 1] - 48 > 5) ? (lowres[n - 2]++) : 0;
		lowres[n - 1] = 48;
		if (n > 2 && lowres[n - 2] == 58)
		{
			lowres[n - 2] = 48;
			lowres[n - 3]++;
		}
	}
	if (lowres[0] == 58)
	{
		lowres[0] -= 10;
		return (1);
	}
	return (0);
}

void			ft_round(char **res)
{
	int		n;
	int		tmp;
	char	*big;

	tmp = 0;
	n = ft_strlen(*res);
	while (n > 0)
	{
		if (*res[n - 1] == 57)
			*res[n - 1] = 48;
		else
			*res[n - 1] += 1;
		if (*res[n - 1] != 48)
			break ;
		n--;
	}
	if (n)
		return ;
	big = ft_strjoin("1", *res);
	ft_strdel(res);
	*res = ft_strdup(big);
	ft_strdel(&big);
}

void			ft_strike(t_double *suka, char *trash)
{
	suka->lowres = ft_strdup(&trash[1]);
	if ((int)ft_strlen(suka->lowres) > suka->strike)
		ft_round_off(suka->lowres, suka->strike) ? ft_round(&(suka->res)) : 0;
	else if ((int)ft_strlen(suka->lowres) < suka->strike)
		ft_putzero(&(suka->lowres), suka->strike);
}
