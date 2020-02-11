/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:16:15 by jkarren           #+#    #+#             */
/*   Updated: 2019/10/21 13:49:41 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **root, void const *content, size_t content_size)
{
	t_list *node;

	if ((node = (t_list*)ft_memalloc(sizeof(t_list))))
	{
		if ((node->content = ft_memdup(content, content_size)))
			node->content_size = content_size;
		node->next = *root;
		*root = node;
	}
}
