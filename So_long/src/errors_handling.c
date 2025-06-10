#include "../so_long.h"


void flood_fill(s_map *map, int x, int y, char old, char new)
{
    if (x < 0 || x >= map->width - 1||
         y < 0 || y >= map->height - 1 ||
          map->grid[y][x] == new ||
          map->grid[y][x] != old )
        return ;
    else
    {
        map->grid[y][x] = new;
        flood_fill(map, x + 1, y, old, new);
        flood_fill(map, x - 1, y, old, new);
        flood_fill(map, x, y + 1, old, new);
        flood_fill(map, x, y - 1, old, new);
    }
}

void prepare_to_flood(s_map *map)
{/* 
    s_map *map_copy;

    map_copy = map;
    map_copy->player_x = 1;
    map_copy->player_y = 1;
    flood_fill(map_copy, map_copy->player_x, map_copy->player_y, '0', 'V'); */
    //ALOCAR MEMORIA PARA A COPIA
}