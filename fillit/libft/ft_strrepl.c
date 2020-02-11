/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:53:19 by jkarren           #+#    #+#             */
/*   Updated: 2019/11/28 18:45:47 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrepl(char *str, const char c, const char replacement)
{
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				*str = replacement;
			str++;
		}
	}
}
