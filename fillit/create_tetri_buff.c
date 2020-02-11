/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri_buff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:13:24 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 17:08:07 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** parse string symbols one by other
** check if there's symbol that's not [. or # or \n]
** check if every \n is on its place after 4 other symbols
** replace every # to letter from A to Z
*/

int		replace_tetri_to_letters(char *tetri_buff)
{
	int		i;
	char	replacement;
	int		nl_cnt;

	replacement = 'A';
	i = -1;
	nl_cnt = 0;
	while (tetri_buff[++i])
	{
		if (!valid_symbol(tetri_buff[i]))
			return (0);
		if (tetri_buff[i] == TETRI)
			tetri_buff[i] = replacement;
		if (i && (i + 1) % T_COLS == 0 && tetri_buff[i] == NEWLINE)
			++nl_cnt;
		else if (i && (i + 1) % T_COLS == 0 && tetri_buff[i] != NEWLINE)
			return (0);
		if (nl_cnt && nl_cnt % T_ROWS == 0)
		{
			replacement++;
			nl_cnt = 0;
		}
	}
	return (1);
}

/*
** del all in-between newlines
** check if rows count don't match with inb count
*/

int		del_inb_newlines(char *tetri_buff)
{
	int	i;
	int	j;
	int	ln;
	int	inb_nl;

	inb_nl = 0;
	i = -1;
	ln = ft_strlen(tetri_buff);
	while (tetri_buff[++i])
		if (tetri_buff[i] == NEWLINE &&
				tetri_buff[i - 1] == NEWLINE)
		{
			++inb_nl;
			j = i - 1;
			while (tetri_buff[++j])
				tetri_buff[j] = tetri_buff[j + 1];
		}
	if (!(valid_rows(inb_nl, ln)))
		return (0);
	return (1);
}

/*
** at first, do formal check
** if newline at the first place in string
** if there're more than 2 newlines in-between
** if there're 2 or more newlines at the end of string
** than del inb newlines and replace # to letters
** than check if there're only four letters in tetromino
** and finaly check shapes
*/

int		valid_tetri_buff(char *tetri_buff)
{
	if (!valid_newlines(tetri_buff))
		return (0);
	if (!del_inb_newlines(tetri_buff))
		return (0);
	if (!replace_tetri_to_letters(tetri_buff))
		return (0);
	if (!four_letter(tetri_buff))
		return (0);
	if (!valid_shapes(tetri_buff))
		return (0);
	return (1);
}

/*
** read from file to Big Enough File string and check
** if there's less than 1 tetro
** if thre's more than 26 tetro
*/

int		read_from_file(int fd, char *buff, int size)
{
	int	read_size;

	if ((read_size = read(fd, buff, size)) < 0)
		return (0);
	if (read_size < T_SIZE)
		return (0);
	else if (read_size > MAX_SIZE)
		return (0);
	return (read_size);
}

/*
** first create Big Enough File to read more than 26 tetro
** copy real tetro from BEF to real-size string
** del BEF
** check all string validations
** if not valid tetro string
** del string
*/

char	*create_tetri_buff(char *tetri_file)
{
	char	*tetri_buff;
	char	*tmp;
	int		read_size;
	int		fd;

	if ((fd = open(tetri_file, O_RDONLY)) < 0)
		return (NULL);
	if (!(tmp = ft_strnew(MAX_SIZE + OVERFLOW)))
		return (NULL);
	if (!(read_size = read_from_file(fd, tmp, MAX_SIZE + OVERFLOW - 1)))
		return (NULL);
	tmp[read_size] = '\0';
	if (!(tetri_buff = ft_strnew(ft_strlen(tmp))))
		return (NULL);
	tetri_buff = ft_strdup(tmp);
	ft_strdel(&tmp);
	if (!valid_tetri_buff(tetri_buff))
	{
		ft_strdel(&tetri_buff);
		return (NULL);
	}
	return (tetri_buff);
}
