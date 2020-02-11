/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:52:51 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/28 15:24:15 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;

	loc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			loc = (char *)s;
		s++;
	}
	if (c == '\0')
		loc = (char *)s;
	return (loc);
}
