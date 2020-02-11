/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:25:32 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 23:15:39 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split(char *str, const char lim_ch)
{
	char	**arr;
	int		i;
	int		i_str;
	int		i_arr;

	if (!(arr = (char **)malloc(sizeof(char *) *
					(ft_wordscount(str, lim_ch) + 1))))
		return (NULL);
	i = -1;
	i_arr = -1;
	while (str[++i])
		if (str[i] != lim_ch)
		{
			if (i_arr == -1 || str[i - 1] == lim_ch)
			{
				if (!(arr[++i_arr] = (char *)malloc(sizeof(char) *
								(ft_wordlen(str + i, lim_ch) + 1))))
					return (NULL);
				i_str = 0;
			}
			arr[i_arr][i_str] = str[i];
			arr[i_arr][++i_str] = '\0';
		}
	arr[++i_arr] = 0;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	if (!s || !c)
		return (NULL);
	return (ft_split((char *)s, c));
}
