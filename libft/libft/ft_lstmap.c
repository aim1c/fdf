/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:33:44 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/16 01:13:58 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nul_content(void *s, size_t n)
{
	free(s);
	s = NULL;
	n = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*tmp2;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(map = f(lst)))
		return (NULL);
	tmp2 = map;
	while (lst->next)
	{
		if (!(map->next = f(lst->next)))
		{
			ft_lstdel(&tmp2, &ft_nul_content);
			return (NULL);
		}
		map = map->next;
		lst = lst->next;
	}
	return (tmp2);
}
