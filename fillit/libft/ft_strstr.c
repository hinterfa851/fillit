/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:53:03 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/28 15:03:19 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	ndl_len;

	ndl_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, ndl_len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
