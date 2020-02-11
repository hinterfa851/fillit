/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:50:10 by jkarren           #+#    #+#             */
/*   Updated: 2019/11/28 18:44:25 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsdel(char *str, const char *arr)
{
	size_t	i;
	size_t	j;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_isinarr(str[i], (char*)arr))
			{
				j = i;
				while (str[j])
				{
					str[j] = str[j + 1];
					++j;
				}
			}
			if (!ft_isinarr(str[i], (char*)arr))
				++i;
		}
	}
}
