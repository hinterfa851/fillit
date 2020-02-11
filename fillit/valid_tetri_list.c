/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetri_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:14:17 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 17:25:27 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	noletters(char **tetri_arr)
{
	int	i;
	int	j;

	i = -1;
	while (tetri_arr[++i])
	{
		j = -1;
		while (tetri_arr[i][++j])
			if (ft_isalpha(tetri_arr[i][j]))
				tetri_arr[i][j] = TETRI;
	}
}

void	append(t_tetri **head, char **tetri_arr, int tetri_height)
{
	t_tetri	*node;
	t_tetri	*last;
	int		i;

	node = (t_tetri*)malloc(sizeof(t_tetri));
	last = *head;
	node->tetromino = (char**)malloc(sizeof(char*) * (tetri_height + 1));
	node->tetri_height = tetri_height;
	i = -1;
	while (++i < tetri_height)
	{
		node->tetromino[i] = *tetri_arr;
		tetri_arr++;
	}
	node->tetromino[i] = ft_strnew(1);
	node->next = NULL;
	if (!(*head))
	{
		*head = node;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = node;
}

int		get_tetri_height(char **tetri_arr, int i)
{
	int		height;
	char	letter;

	height = 1;
	letter = tetri_arr[i][0];
	while (tetri_arr[i + height] && tetri_arr[i + height][0] == letter)
		++height;
	return (height);
}

t_tetri	*create_tetri_list(char **tetri_arr)
{
	static t_tetri	*head;
	char			**tmp;
	int				tetri_height;
	int				i;

	head = NULL;
	tmp = tetri_arr;
	tetri_height = 0;
	while (*tmp)
	{
		i = 0;
		tetri_height = get_tetri_height(tmp, i);
		append(&head, tmp, tetri_height);
		i += tetri_height;
		tmp += tetri_height;
	}
	return (head);
}

t_tetri	*valid_tetri_list(char *tetri_file)
{
	t_tetri	*tetri_list;
	char	*tetri_buff;
	char	**tetri_arr;

	if (!(tetri_buff = create_tetri_buff(tetri_file)))
		return (NULL);
	del_empty_space(tetri_buff);
	if (!(tetri_arr = create_tetri_arr(tetri_buff)))
		return (NULL);
	if (!(tetri_list = create_tetri_list(tetri_arr)))
		return (NULL);
	/*noletters(tetri_arr);*/
	return (tetri_list);
}
