/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrepl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:53:37 by jkarren           #+#    #+#             */
/*   Updated: 2019/11/01 14:04:52 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsrepl(char *str, const char *arr, const char replacement)
{
	if (str)
	{
		while (*str)
		{
			if (ft_isinarr(*str, (char*)arr))
				*str = replacement;
			str++;
		}
	}
}
