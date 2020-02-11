/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:38:47 by jkarren           #+#    #+#             */
/*   Updated: 2019/10/21 13:30:03 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *content, size_t content_size)
{
	void	*new;
	size_t	i;

	i = 0;
	if ((new = ft_memalloc(content_size)))
	{
		while (((unsigned char *)content)[i])
		{
			((unsigned char *)new)[i] = ((unsigned char *)content)[i];
			++i;
		}
		return (new);
	}
	return (NULL);
}
