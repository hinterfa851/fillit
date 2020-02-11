/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:36:46 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 17:41:45 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** this is unnecessary funcs created for checking errors needs
*/

void	print_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_putendl(arr[i]);
}

void	print_tetromino(char **tetromino, int tetri_height)
{
	int	i;

	i = -1;
	while (++i <= tetri_height)
		ft_putendl(tetromino[i]);
}

void	print_tetri_list(t_tetri **head)
{
	t_tetri	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_putendl("tmp->tetromino:");
		print_tetromino(tmp->tetromino, tmp->tetri_height);
		tmp = tmp->next;
	}
}
