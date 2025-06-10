/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/09 20:34:02 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    int i = 0;
    s_map *map = load_map(argv[1]);
    if (!map)
        ft_printf("erro ao dar load no mapa");
    if (argc != 2)
        return (ft_printf("Argumento invalido!"));
    //verificar se e realmente um mapa

    ft_printf("\nreturn: %d\n\n", check_walls(map));
    
    while (map->grid[i] != NULL)
    ft_printf("%s\n", map->grid[i++]);
    ft_printf("height: %d\n", map->height);
    ft_printf("width: %d\n", map->width);
    clean_mem(map);
}  