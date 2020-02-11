/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:54:29 by jkarren           #+#    #+#             */
/*   Updated: 2019/10/21 14:01:55 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *root;

	if ((root = (t_list*)ft_memalloc(sizeof(t_list))))
	{
		if (content)
		{
			if ((root->content = ft_memdup(content, content_size)))
				root->content_size = content_size;
			else
				return (NULL);
		}
		else
		{
			root->content = NULL;
			root->content_size = 0;
		}
		root->next = NULL;
		return (root);
	}
	return (NULL);
}
