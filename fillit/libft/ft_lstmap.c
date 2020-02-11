/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 12:33:04 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/28 12:39:15 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*newlist;

	if (!f || !lst)
		return (NULL);
	newlist = (t_list *)malloc(sizeof(t_list) * 1);
	if (!newlist)
		return (NULL);
	newlist = f(lst);
	buf = newlist;
	while (lst->next)
	{
		newlist->next = (t_list *)malloc(sizeof(t_list) * 1);
		if (!newlist->next)
			return (NULL);
		newlist->next = f(lst->next);
		newlist = newlist->next;
		lst = lst->next;
	}
	newlist->next = NULL;
	return (buf);
}
