/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:53:20 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/28 14:58:44 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t ndl_len;

	if (!*needle)
		return ((char *)haystack);
	ndl_len = ft_strlen(needle);
	while (*haystack && ndl_len <= len--)
	{
		if (!ft_strncmp(haystack, needle, ndl_len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
