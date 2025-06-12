#ifndef SO_LONG_H
#define SO_LONG_H

#include "Libft/libft.h"

typedef struct map_infos
{
    char **grid;
    int width;
    int height;
    int collectables;
    int player_x;
    int player_y;
} s_map;

s_map   *prepare_to_flood(s_map *map);
s_map   *load_map(char *filename);
int     check_if_map_is_valid(s_map *map);
int     check_collectables(s_map *map);
int     check_characters(s_map *map);
int     check_format(s_map * map);
int     check_player(s_map *map);
int     check_walls(s_map *map);
int     check_exit(s_map *map);
void    clean_mem(s_map *map);
void    flood_fill(s_map *map, int x, int y, char old, char new);



#endif