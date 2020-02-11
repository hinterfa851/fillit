/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_buff2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:03:42 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 17:06:04 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** nice function to find shapes
*/

int		get_letter_shapes(char *tetri_buff, int i, char letter)
{
	int	shapes;

	shapes = 0;
	if (i && tetri_buff[i - 1] == letter)
	   ++shapes;
	if (tetri_buff[i + 1] && tetri_buff[i + 1] == letter)
		++shapes;
	if (i >= T_COLS && tetri_buff[i - T_COLS] == letter)
		++shapes;
	if (tetri_buff[i + T_COLS] && tetri_buff[i + T_COLS] == letter)
		++shapes;
	return (shapes);
}

int		valid_shapes(char *tetri_buff)
{
	int		i;
	char	letter;
	int		shapes;

	i = -1;
	letter = 'A';
	shapes = 0;
	while (tetri_buff[++i])
	{
		if (tetri_buff[i] == letter)
			shapes += get_letter_shapes(tetri_buff, i, letter);
		if (tetri_buff[i] != letter && ft_isalpha(tetri_buff[i]))
		{
			if (!(shapes == 6 || shapes == 8))
			   return (0);
			--i;
			letter++;
			shapes = 0;
		}
	}
	if (shapes && !(shapes == 6 || shapes == 8))
		return (0);
	return (1);
}
