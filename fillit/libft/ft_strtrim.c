/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:50:00 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/28 15:53:08 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	char		*ret;
	int			j;

	start = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
	{
		start++;
		if (s[start] == '\0')
			j = 1;
	}
	while (j == 0 && (s[end - 1] == ' ' || s[end - 1] == '\t'
				|| s[end - 1] == '\n'))
		end--;
	ret = ft_strnew(end - start);
	if (ret == NULL)
		return (NULL);
	return (ft_strncpy(ret, s + start, end - start));
}
