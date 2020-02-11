/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetrominoes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:42:45 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/11 18:09:00 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void prnt_rr(char **arr)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(arr[0]);
    //   while(i < 4 && *(arr[i]))
    while(i <= len)
    {
        printf("%s\n", arr[i]);
        i++;
    }
}

void	solve_tetrominoes(t_tetri **tetrominoes)
{
	t_tetri	*tetr;
    char **map;
    int n;
    int d;

    n = 2;
	tetr = *tetrominoes;
    map = cr_free_map(n);
//	ft_putendl("init map:");
//	print_arr(map);
    while ((d = calculate(tetr, &map)) == 0) {
//		printf("Here\n");
		map = cr_free_map(++n);
    }
    if (d == 10)
        printf("error\n");
    else
        prnt_rr(map);
}
