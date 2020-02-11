/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:59:20 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 18:09:09 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# include <fcntl.h>
# include "./libft/libft.h"

#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strchr.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strlen.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strsub.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strdel.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strdup.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strjoin.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strcpy.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strnew.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_memdel.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strcat.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strncpy.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_bzero.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_isinarr.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_memalloc.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_putendl.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strsplit.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_putchar.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_putstr.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_wordcount.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_putchar_fd.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_putendl_fd.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_putstr_fd.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_wordscount.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_wordlen.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_isalpha.c"
#include "/Users/hinterfa/Documents/hinterfa/fillit/libft/ft_strcdel.c"


# define NEWLINE '\n'
# define EMPTY '.'
# define TETRI '#'
# define T_ROWS 4
# define T_COLS 5
# define T_SIZE 20
# define T_CNT 26
# define NL_INB 25
# define MAX_SIZE 545
# define OVERFLOW 10
# define TRASH '0'

typedef struct	s_tetri
{
	char			**tetromino;
	int				tetri_height;
	struct s_tetri	*next;
}				t_tetri;

#include "util.c"
#include "del_empty_lines.c"
#include "validate_buff.c"
#include "validate_buff2.c"
#include "create_tetri_buff.c"
#include "create_tetri_arr.c"
#include "valid_tetri_list.c"
#include "alg.c"
#include "solve_tetrominoes.c"
/*
** util functions for checking if everything's alright
** when we go from validation to algorithm
**
** actually don't need but saved for next cases
*/
/*
void			print_tetromino(char **tetromino, int tetri_height);
void			print_tetri_list(t_tetri **head);
void			print_arr(char **arr);

int				get_tetri_height(char **tetri_arr, int i);
void			noletters(char **tetri_arr);


t_tetri			*valid_tetri_list(char *tetri_file);
t_tetri			*create_tetri_list(char **tetri_arr);
void			append(t_tetri **head, char **tetri_arr, int tetri_height);


char			*create_tetri_buff(char *tetri_file);
int				read_from_file(int fd, char *buff, int size);
int				valid_tetri_buff(char *tetri_buff);
int				del_inb_newlines(char *tetri_buff);
int				replace_tetri_to_letters(char *tetri_buff);
void			del_empty_space(char *tetri_buff);


char			**create_tetri_arr(char *tetri_buff);


int				valid_newlines(char *tetri_buff);
int				valid_symbol(char c);
int				valid_rows(int newlines, int symbols);
int				invalid_cols(void);
int				valid_tetromino(char **tetri_arr);
int				tetromino_shapes(char tetri, char **tetri_arr,
		int start, int end);
int				count_letters(char tetri, char **tetri_arr,
		int start, int end);
int				count_shapes(char tetri, char **tetri_arr, int row, int col);
int				four_letter(char *tetri_buff);
int				valid_shapes(char *tetri_buff);
int				get_letter_shapes(char *tetri_buff, int i, char letter);


void			solve_tetrominoes(t_tetri **tetrominoes);
int				check(char **map, char **arr, int *cur_coor);
int				place(char **arr, char **map, char ***new, int *variant);
int				ft_write(char **map, char **arr, int *cur_coor, char ***new);
void			addchr(char **arr, int n);
char			**cr_free_map(int n);
int				calculate(t_tetri *tetr, char ***map);
int				*ft_finder(char **map, int n);
*/
// HELL IS IT ENOUGH?

#endif
