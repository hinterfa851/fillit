/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:01:51 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 23:06:23 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordscount(char *str, const char lim_ch)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] && str[i] == lim_ch)
		++i;
	if (str[i] && str[i] != lim_ch)
		++count;
	while (str[i])
	{
		if (str[i] != lim_ch && str[i - 1] == lim_ch)
			++count;
		++i;
	}
	return (count);
}
