int check(char **map, char *arr[], int *cur_coor);

int place(char **arr, char **map, char ***new , int *variant);

int ft_write(char **map, char **arr, int *cur_coor, char ***new);

char	**ft_freesher(char **str, int len)
{
    int i;

    i = 0;
    if (!str)
        return (NULL);
    while (i < len)
    {
        free(str[i]);
        i++;
    }
    free(str);
    return (NULL);
}


int arr_len(char **arr)
{
    int i;

    i = 0;
    if (arr)
    {
        if (*arr )
            i++;
    }
    return (i);
}

void addchr(char **arr, int n)                  // create line for cr_map
{
    int i;

    i = 0;
    while (i < n)
        (*arr)[i++] = '.';
    (*arr)[i] = '\0';
}

char **cr_free_map(int n)                //  create free map n-size
{
    char **res;
    int i;

    i = 0;
    res = malloc((n + 1) * sizeof(char *));
    while (i < n)
        res[i++] = malloc(n + 1);
    res[i] = malloc(1);
    *(res[i--]) = '\0';
    while (i >= 0)
    {
        addchr(&(res[i]), n);
        i--;
    }
    return (res);
}


int calculate(t_tetri *tetr, char ***map)               // actual version
{
    char **new;
    int variant = 0;

    if ((*((tetr->tetromino)[0])) == '\0')
        return (10);
    while ((place(tetr->tetromino, *map, &new, &variant)) == 1)
    {
        variant++;
        if (tetr->next)
        {
            int res = calculate(tetr->next, &new);
            if (res == 1)
            {
                ft_freesher(*map, ft_strlen((*map)[0]) + 1);
                *map = new;
                return (1);
            }
 //           printf("%d\n", ft_strlen(new[0]));
            ft_freesher(new, ft_strlen(new[0]) + 1);
        }
        else {
            ft_freesher(*map, ft_strlen((*map)[0]) + 1);
            *map = new;
//            ft_freesher(new, 1);
            return (1);
        }
 //       ft_freesher(new, ft_strlen(new[0]));
    }
//    ft_freesher(new, ft_strlen(new[0]));
    return (0);
}

int *ft_finder(char **map, int n)
{
    static int cur_coor[3];
    int len;

    len = ft_strlen(*map);                                               //   count number of
    cur_coor[1] = n / len;                                      //  calculate row                                                       //  ATTENTION!!!!!!!!!!!!
    cur_coor[0] = n % len;                                      // calculate column                                                     //  ATTTENTION!!!!!!!!!!!!!
    cur_coor[2] = len;
    return (cur_coor);
}


int place(char **arr, char **map, char ***new , int *variant)           //(tetramino, old map, map to copy and write, position to place)
{
   int *cur_coor;

   cur_coor = ft_finder(map, *variant);
   while (*variant < (cur_coor[2] * cur_coor[2]))               // !!!!!!!!!!!! TOOOO MUCH, REALLY??? LOL!!!!!!!!!!
   {
       cur_coor = ft_finder(map, *variant);
       if (map[cur_coor[1]][cur_coor[0]] == '.')
       {
  //         prnt_rr(arr);
           if (check(map, arr, cur_coor))
           {
               ft_write(map, arr, cur_coor, new);
   //            (*variant)++;
               return (1);
           }
           else
               (*variant)++;
       }
       else
           (*variant)++;
   }
//   ft_freesher(new, 1);
   return (0);
}

/*
char **cp_arr_full(char **map, int len)
{
    int i;
    char **new;

    i = 0;
    new = malloc(sizeof(char *) * (len));
    while(i < len)
    {
        (new)[i] = ft_strdup(map[i]);
        i++;
    }
    (new)[i] = malloc(1);
    (*(new[i])) = '\0';
    return (new);
}
*/
void cp_arr_full(char **map, char ***new, int len)
{
    int i;

    i = 0;
 //   if (*new)
 //       printf("%s\n", (*new)[1]);
    *new = malloc(sizeof(char *) * (len + 1));
    while(i < len)
    {
        (*new)[i] = ft_strdup(map[i]);
        i++;
    }
    (*new)[i] = malloc(1);
    *((*new)[i]) = '\0';
}

/*
int ft_write(char **map, char **arr, int *cur_coor, char ***new)
{
    int count;
    int offset;
    int len;
    char **dies;

    count = 0;
    offset = 0;
    len = 0;
    dies = cp_arr_full(arr,  4);
    *new = cp_arr_full(map, cur_coor[2]);
    while (((dies[len][count]) != '.') && ((dies[len][count]) != '\0'))
    {
        while (((dies[len][count]) != '.') && ((dies[len][count]) != '\0'))
        {
            (*new)[cur_coor[1] + count][cur_coor[0] + offset] = arr[0][0];
            offset++;
            len++;
        }
        count++;
        if (count != 4)
            offset = (ft_strlen(arr[0]) == ft_strlen(arr[count])) ? 0 : len - ft_strlen(arr[count]);
    }
    dies-= count;
//    ft_freesher(dies, 4);
//    free(dies[-8]);
    return (1);
}
*/

/*
int ft_write(char **map, char **arr, int *cur_coor, char ***new)
{
    int count;
    int offset;
    int len;
    char **dies;
    int row;

    count = 0;
    offset = 0;
    row = 0;
    len = ft_strlen(arr[count]);
    dies = cp_arr_full(arr,  4);
    *new = cp_arr_full(map, cur_coor[2]);
 //   prnt_rr(dies);
    while (((dies[count][0]) != '.') && ((dies[count][0]) != '\0'))
    {
        while (((dies[count][row]) != '.') && ((dies[count][row]) != '\0'))
        {
            (*new)[cur_coor[1] + count][cur_coor[0] + offset] = dies[0][0];
            offset++;
            row++;
        }
        row = 0;
        count++;
        if (count != 4)
            offset = (len == ft_strlen(arr[count])) ? 0 : len - ft_strlen(arr[count]);
    }
  //  printf("%s\n", dies[0]);
   // free(dies[]);
//    prnt_rr(new);
//    ft_freesher(dies, 4);
    return (1);
}
*/

int ft_write(char **map, char **arr, int *cur_coor, char ***new)
{
    int count;
    int offset;
    int len;
    int ttt;

    ttt = 0;
    count = 0;
    offset = 0;
    len = ft_strlen(arr[count]);
    cp_arr_full(map, new, cur_coor[2]);
    while (((arr[count][0]) != '.') && ((arr[count][0]) != '\0'))
    {
        while (((arr[count][ttt]) != '.') && ((arr[count][ttt]) != '\0'))
        {
            (*new)[cur_coor[1] + count][cur_coor[0] + offset] = arr[0][0];
            offset++;
            ttt++;
        }
        ttt = 0;
        count++;
        if (count != 4)
            offset = (len == ft_strlen(arr[count])) ? 0 : len - ft_strlen(arr[count]);
    }
    return (1);
}

/*
int ft_write(char **map, char **arr, int *cur_coor, char ***new)
{
    int count;
    int offset;
    int len;
    int row;

    count = 0;
    offset = 0;
    row = 0;
    len = ft_strlen(arr[count]);
    *new = cp_arr_full(map, cur_coor[2]);
    while (((arr[count][0]) != '.') && (((arr[count][0]) ) != '\0'))
    {
        while (((arr[count][row]) != '.') && ((arr[count][row]) != '\0'))
        {
            (*new)[cur_coor[1] + count][cur_coor[0] + offset] = arr[0][0];
            offset++;
            row++;
        }
        row = 0;
        count++;
        if (count != 4)
            offset = (len == ft_strlen(arr[count])) ? 0 : len - ft_strlen(arr[count]);
    }
    //  printf("%s\n", dies[0]);
    // free(dies[]);
    return (1);
}
*/

int check(char **map, char **arr, int *cur_coor)
{
    int count;
    int offset;
    int len;
    int ttt;

    count = 0;
    offset = 0;
    ttt = 0;
    len = ft_strlen(arr[0]);
    while (((arr[count][0]) != '.') && ((arr[count][0]) != '\0'))
    {
        if (cur_coor[1] + count > cur_coor[2])
            return (0);
        while (((arr[count][ttt]) != '.') && ((arr[count][ttt]) != '\0'))
        {
            if (cur_coor[0] + offset > cur_coor[2])
                return (0);
            if ((map[cur_coor[1] + count][cur_coor[0] + offset] != '.'))
                return (0);
            offset++;
            ttt++;
        }
        ttt = 0;
        if (++count != 4)
            offset = (len == ft_strlen(arr[count])) ? 0 : len - ft_strlen(arr[count]);
    }
    return (1);
}

/*
int check(char **map, char **arr, int *cur_coor)
{
    int count;
    int offset;
    int len;
    char **dies;
    int row;

    row = 0;
    count = 0;
    offset = 0;
    dies = cp_arr_full(arr, 4);
    len = ft_strlen(arr[0]);
    while (((*dies[count]) != '.') && ((*dies[count]) != '\0'))
    {
        if (cur_coor[1] + count > cur_coor[2])                                                  //nuul free
        {
  //          ft_freesher(dies, 4);
            return (0);
        }
        while (((dies[count][row]) != '.') && ((dies[count][row]) != '\0'))
        {
            if (cur_coor[0] + offset > cur_coor[2])                                                 // nuul free
            {
   //             ft_freesher(dies, 4);
                return (0);
            }
            if ((map[cur_coor[1] + count][cur_coor[0] + offset] != '.'))
            {
 //               ft_freesher(dies, 4);
                return (0);
            }
            offset++;
            row++;
        }
        row = 0;
        if (++count != 4)
            offset = (len == ft_strlen(arr[count])) ? 0 : len - ft_strlen(arr[count]);
    }
//    ft_freesher(dies, 4);
    return (1);
}
*/
