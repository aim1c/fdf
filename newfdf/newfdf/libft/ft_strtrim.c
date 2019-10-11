/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:15:34 by masprigg          #+#    #+#             */
/*   Updated: 2018/11/30 21:17:16 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_stattrim(char const *s)
{
	char	*trim;
	int		len;
	int		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *(s++))
		len--;
	while (*s != '\0')
		s++;
	s--;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *(s--))
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

char			*ft_strtrim(char const *s)
{
	int		che;
	int		l;
	char	*trim;

	che = 0;
	l = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			che++;
		s++;
	}
	s = s - l;
	if (che == 0)
	{
		trim = (char*)malloc(1);
		*trim = '\0';
	}
	else if (!(trim = ft_stattrim(s)))
		return (NULL);
	return (trim);
}
