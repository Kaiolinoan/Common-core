/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/12 15:35:53 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    int i = 0;
    s_map *new;
    s_map *map = load_map(argv[1]);
    if (!map)
        ft_printf("erro ao dar load no mapa");
    if (argc != 2)
        return (ft_printf("Argumento invalido!"));
    ft_printf("---%d---\n", check_if_map_is_valid(map));
        //  TESTE FLOOD FILL
     ft_printf("Before\n");
     while (map->grid[i] != NULL)
         ft_printf("%s\n", map->grid[i++]);
    
    new = prepare_to_flood(map);
    ft_printf("X: %d, Y: %d\n", new->player_x, new->player_y);
    
     i = 0;
        ft_printf("After\n");
     while (new->grid[i] != NULL)
         ft_printf("%s\n", new->grid[i++]);
    
    // clean_mem(map);
}  
/*             TESTE NEW MAP
    ft_printf("original:\n");
    ft_printf("height: %d\n", map->height);
    ft_printf("width: %d\n", map->width);
     while (map->grid[i] != NULL)
     ft_printf("%s\n", map->grid[i++]);
     new = prepare_to_flood(map);
     i = 0;
    ft_printf("new:\n");
    ft_printf("height: %d\n", new->height);
    ft_printf("width: %d\n", new->width);
     while (new->grid[i] != NULL)
     ft_printf("%s\n", new->grid[i++]); */