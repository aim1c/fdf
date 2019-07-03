/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supertrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:24:52 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/12 22:44:35 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stattrim(char const *s, char c)
{
	char	*trim;
	int		len;
	int		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = (int)ft_strlen(s);
	while (*s == c && *(s++))
		len--;
	while (*s != '\0')
		s++;
	s--;
	while (*s == c && *(s--))
		len--;
	if (!(trim = (char*)malloc(len + 1)))
		return (NULL);
	s = s - len + 1;
	while (++i < len)
	{
		*trim = *(s++);
		trim++;
	}
	*trim = '\0';
	return (trim - len);
}

char		*ft_supertrim(char const *s, char c)
{
	int		che;
	int		l;
	char	*trim;

	che = 0;
	l = 0;
	if (s == NULL)
		return (NULL);
	l = (int)ft_strlen(s);
	while (*s)
	{
		if (*s != c)
			che++;
		s++;
	}
	s = s - l;
	if (che == 0)
	{
		trim = (char*)malloc(1);
		*trim = '\0';
	}
	else if (!(trim = ft_stattrim(s, c)))
		return (NULL);
	return (trim);
}
