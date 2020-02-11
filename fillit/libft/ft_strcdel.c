/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:53:02 by jkarren           #+#    #+#             */
/*   Updated: 2019/11/28 18:48:29 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcdel(char *str, const char c)
{
	size_t	i;
	size_t	j;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == c)
			{
				j = i;
				while (str[j])
				{
					str[j] = str[j + 1];
					++j;
				}
			}
			else
				++i;
		}
	}
}
