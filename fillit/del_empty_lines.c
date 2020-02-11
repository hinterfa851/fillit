/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_empty_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:26:23 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 13:39:58 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** here we replace all empty lines to 'magick symbol' yey %)
** also we replace all initial dots
** and delete magick symbols to hell
*/

void	del_empty_space(char *tetri_buff)
{
	int	i;

	i = 0;
	while (tetri_buff[i])
	{
		if (tetri_buff[i] == EMPTY)
			tetri_buff[i] = TRASH;
		if (ft_isalpha(tetri_buff[i]))
			while (tetri_buff[i] != NEWLINE)
				++i;
		if (tetri_buff[i] == NEWLINE && tetri_buff[i - 1] == TRASH)
			tetri_buff[i] = TRASH;
		++i;
	}
	ft_strcdel(tetri_buff, TRASH);
}
