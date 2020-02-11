/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:13:12 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 14:44:37 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 'cause in previous step I get valid string delimited by \n
** I can use strsplit to split it line by line
*/

char	**create_tetri_arr(char *tetri_buff)
{
	char	**tetri_arr;

	tetri_arr = ft_strsplit(tetri_buff, NEWLINE);
	return (tetri_arr);
}
