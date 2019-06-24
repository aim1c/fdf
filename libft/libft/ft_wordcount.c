/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:02:27 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char c)
{
	size_t		size;

	size = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size++;
			while (*s != c && *s)
				s++;
		}
	}
	return (size);
}
