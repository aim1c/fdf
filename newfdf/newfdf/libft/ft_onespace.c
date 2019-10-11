/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onespace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:05:51 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/12 20:54:30 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenspace(char const *str, char c)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			l++;
		i++;
	}
	return (l);
}

static int	ft_lnosp(char const *str, char c)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] != c)
			l++;
		i++;
	}
	return (l);
}

char		*ft_onespace(char *str, char c)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(res = malloc(ft_lnosp(str, c) + ft_lenspace(str, c) + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
		{
			res[j] = str[i];
			j++;
		}
		else if (str[i] != c)
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
