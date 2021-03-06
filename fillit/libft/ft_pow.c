/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:25:10 by jkarren           #+#    #+#             */
/*   Updated: 2019/12/04 18:25:32 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int x, int y)
{
	int	i;
	int	rst;

	i = y;
	rst = x;
	if (y == 0)
		return (1);
	while (--i >= 0)
		rst *= x;
	return (rst);
}
