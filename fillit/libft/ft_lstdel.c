/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 12:32:19 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/28 19:38:45 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst_i;
	t_list	*tmp;

	lst_i = *alst;
	while (lst_i)
	{
		tmp = lst_i;
		ft_lstdelone(&lst_i, del);
		lst_i = tmp->next;
	}
	*alst = NULL;
}
