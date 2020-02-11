/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:17:15 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 18:55:31 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = ((*str++ == '-') ? -1 : 1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (num < 0)
				return (num);
			if (num > 922337293685477580 && sign == 1)
				return (-1);
			if (num >= 922337203685477580 && *str >= '8' && sign == -1)
				return (0);
			num = (*str++ - '0') + num * 10;
		}
		else
			return (num * sign);
	}
	return (num * sign);
}
