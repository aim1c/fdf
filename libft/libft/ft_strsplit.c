/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:53:38 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/23 23:59:03 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_fnn(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
	split = NULL;
	return (NULL);
}

static int		ft_countword(char *str, char c)
{
	int		i;
	int		l;

	i = 0;
	l = 1;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			l++;
		i++;
	}
	return (l);
}

static int		ft_lenpart(char *str, char c, int n)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	while (i < n && str[j])
	{
		if (str[j] == c)
			i++;
		j++;
	}
	while (str[j] != c && str[j++])
		l++;
	return (l);
}

static char		**ft_makesplit(char *str, char c)
{
	char	**split;
	int		i;
	int		j;
	int		n;

	i = -1;
	j = 0;
	n = 0;
	if (!(split = (char**)malloc(sizeof(*split) * (ft_countword(str, c) + 1))))
		return (NULL);
	while (++i < ft_countword(str, c))
	{
		if (!(split[i] = malloc(sizeof(split) * (ft_lenpart(str, c, i) + 1))))
			return (ft_fnn(split, i));
		while (str[n] != c && str[n])
			split[i][j++] = str[n++];
		split[i][j] = '\0';
		j = 0;
		if (str[n] == c)
			n++;
	}
	split[i] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	*res;
	char	**split;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_supertrim(s, c)))
		return (NULL);
	if (!(res = ft_onespace(str, c)))
	{
		free(str);
		return (NULL);
	}
	free(str);
	str = NULL;
	if (!(split = ft_makesplit(res, c)))
	{
		free(res);
		return (NULL);
	}
	free(res);
	res = NULL;
	return (split);
}
