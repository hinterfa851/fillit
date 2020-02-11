#include "fillit.h"


void fr_struct(t_tetri **list)
{
    t_tetri *del;

    while((*list))
    {
        del = (*list)->next;
        ft_freesher((*list)->tetromino, 5);
        free(*list);
        *list = del;
    }
  //  ft_freesher((*list)->arr, ft_strlen((((*list)->arr))[0]) + 1 );
  //  free(*list);
  *list = NULL;
}


/*
int main(int argc, char **argv)
{
    tt_list *tetr;
    char **map;
    int n;
    int d;

    n = 2;
    reader_to_lst(&tetr);
    map = cr_free_map(n);
//    write(1, 'a', 2);
    while ((d = calculate(tetr, &map)) == 0) {
 //       ft_freesher(map, n + 1);
        map = cr_free_map(++n);
    }
    if (d == 10)
        printf("error\n");
    else
        prnt_rr(map);
  //  printf("lol");
 //   ft_freesher(map, n + 1);
 //   printf("%s", map[2][2]);
    fr_struct(&tetr);
    return (0);
}
 */
/*
int main(int argc, char **argv)
{
    tt_list *tetr;
    char **map;
    int n;
    int d;

        n = 2;
        reader_to_lst(&tetr, argv[1]);
        map = cr_free_map(n);
        //   count_lst(tetr);
        while ((d = calculate(tetr, &map)) == 0) {
            ft_freesher(map, n + 1);
            map = cr_free_map(++n);
        }
        if (d == 10)
            printf("error\n");
        else
            prnt_rr(map);
        ft_freesher(map, n + 1);
        fr_struct(&tetr);
    return (0);
}
*/
/*
int		main(int ac, char **av)
{
    t_tetri	*tetrominoes;

    if (ac != 2)
        ft_putendl("usage: ./fillit target_file");
    else
    {
        if ((tetrominoes = valid_tetri_list(av[1])))
        {
   //         printf("here\n");
  //          print_tetri_list(&tetrominoes);
            solve_tetrominoes(&tetrominoes);
        }
        else
            ft_putendl("error");
    }
    return (1);
}
*/
int		main(int ac, char **av)
{
    t_tetri	*tetrominoes;

    if (ac != 2)
        ft_putendl("usage: ./fillit target_file");
    else
    {
        if ((tetrominoes = valid_tetri_list(av[1])))
        {
            //         printf("here\n");
            //          print_tetri_list(&tetrominoes);
            solve_tetrominoes(&tetrominoes);
        }
        else
            ft_putendl("error");
    }
    return (1);
}