#include "../so_long.h"

int     check_if_map_is_valid(s_map *map)
{ //COLOCAR EM INGLES
    if (check_format(map) == 0)
        return (ft_printf("Formato invalido"), 0);
    if (check_characters(map) == 0)
        return (ft_printf("Caracter invalido"), 0);
    if (check_walls(map) == 0)
        return (ft_printf("Mapa invalido"), 0);
    if (check_player(map) == 0)
        return (ft_printf("Player invalido"), 0);
    if (check_exit(map) == 0)
        return (ft_printf("Saida invalida"), 0);
    if (check_collectables(map) == 0)
        return (ft_printf("Coletaveis invalidos"), 0);
    return (1);
}

int     check_characters(s_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->grid[i])
    {
        j = 0;
        while(map->grid[i][j])
        {
            if (map->grid[i][j] == '1' || map->grid[i][j] == '0' || map->grid[i][j] == 'P' || map->grid[i][j] == 'E' || map->grid[i][j] == 'C')
                j++;
            else
                return (0);
        }
        i++;
    }
    return (1);
}

int     check_format(s_map * map)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (map->height <= 2)
        return (0);
    else if (map->width <= 2)
        return (0);
    while (map->grid[i])
    {
        len = gnl_strlen(map->grid[i]);
        if (map->width == len)
            i++;
        else
            return (0);
    }
    return (1);
}

int check_walls(s_map *map)
{
    int i;
    int j;
    int imax;
    int jmax;

    i = 0;
    j = 0;
    imax = map->height - 1;
    jmax = map->width - 1;
    while (map->grid[i])
    {
        j = 0;
        while(map->grid[i][j])
        {
            if (map->grid[i][j] != '1' && (i == 0 || j == 0 || i == imax || j == jmax))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int check_player(s_map *map)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map->grid[i])
    {
        j = 0;
        while(map->grid[i][j])
        {
            if (map->grid[i][j] == 'P')
            {
                count++;
                map->player_y = i;
                map->player_x = j;
            }
            j++;
        }
        i++;
    }
    if (count != 1)
        return (0);
    return (1);
}

int check_exit(s_map *map)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map->grid[i])
    {
        j = 0;
        while(map->grid[i][j])
        {
            if (map->grid[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    if (count != 1)
        return (0);
    return (1);
}

int check_collectables(s_map *map)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map->grid[i])
    {
        j = 0;
        while(map->grid[i][j])
        {
            if (map->grid[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    map->collectables = count;
    if (count < 1)
        return (0);
    return (1);
}

int check_flood_fill(s_map *map)
{
    static int  exit;
    static int  collectables;

    

}

s_map *prepare_to_flood(s_map *map)
{ 
    s_map *new_map;
    int i;

    i = 0;
    new_map = malloc(sizeof(s_map));
    if (!new_map)
        return (NULL);
    new_map->grid = malloc(sizeof(char *)  * (map->height + 1));
    if (!new_map->grid)
        return (NULL);
    while (map->grid[i])
    {
        new_map->grid[i] = map->grid[i];
        i++;
    }
    new_map->grid[i] = NULL;
    new_map->height = map->height;
    new_map->width = map->width;
    new_map->collectables = map->collectables;
    new_map->player_x = map->player_x;
    new_map->player_y = map->player_y;
    flood_fill(new_map, new_map->player_x, new_map->player_y, '0', 'V');
    return (new_map);
}
