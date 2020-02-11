/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:29:58 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 18:56:58 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		sign;

	sign = 0;
	if (n < 0)
		++sign;
	len = (int)ft_intlen(n);
	str = ft_strnew(len + sign);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	i = len + sign - 1;
	while (i >= sign)
	{
		if (sign)
			str[i--] = (n % 10 * -1) + '0';
		else
			str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
