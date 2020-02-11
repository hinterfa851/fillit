/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:10:58 by jkarren           #+#    #+#             */
/*   Updated: 2019/10/18 15:03:19 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btrnew(void const *content, size_t content_size)
{
	t_btree *nbtr;

	if ((nbtr = (t_btree*)ft_memalloc(sizeof(t_btree))))
	{
		if (content)
		{
			if ((nbtr->content = ft_memdup(content, content_size)))
				nbtr->content_size = content_size;
			else
				return (NULL);
		}
		else
		{
			nbtr->content = NULL;
			nbtr->content_size = 0;
		}
		nbtr->left = NULL;
		nbtr->right = NULL;
		return (nbtr);
	}
	return (NULL);
}
