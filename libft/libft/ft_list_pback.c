/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:59:21 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/15 05:53:50 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_pback(t_list **f, void const *data, size_t c_size)
{
	t_list	*list;

	list = *f;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(data, c_size);
	}
	else
		*f = ft_lstnew(data, c_size);
}
