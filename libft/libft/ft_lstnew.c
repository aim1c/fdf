/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:43:44 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/14 18:15:58 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		content = NULL;
		content_size = 0;
		new->content = NULL;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
		{
			free(new);
			new = NULL;
			return (NULL);
		}
		new->content = ft_memcpy(new->content, content, content_size);
	}
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
