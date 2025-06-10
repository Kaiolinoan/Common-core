/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:17:55 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/09 20:29:42 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h" 
#include "../Libft/libft.h"

static int count_lines(char *filename)
{
    size_t count;
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
       return (perror("Erro"), -1);
    count = 0;
    while ((line = get_next_line(fd)))
    {
        count++;
        free(line);
    }
    close(fd);
    return (count);
}

static s_map *fill_map(s_map *map, char *filename)
{
    int fd;
    char *line;
    size_t i;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        exit(-1);
    i = 0;
    line = NULL;
    while ((line = get_next_line(fd)))
    {
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        map->grid[i++] = line;
    }
    map->width = ft_strlen(map->grid[0]);
    map->grid[i] = NULL;
    close(fd);
    return (map);
}

s_map *load_map(char *filename)
{
    s_map *map;

    map = malloc(sizeof(s_map));
    if (!map)
        return (free(map),NULL);
    if (count_lines(filename) == -1)
    {
        free(map);
        exit(-1);
    }
    map->height = count_lines(filename);
    if (map->height <= 2)
        return (free(map), NULL);
    map->grid = malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
    {
        free (map->grid);
        return (free(map), NULL);
    }
    map = fill_map(map, filename);
    if (!map)
        return (ft_printf("Erro ao preencher o mapa!"), NULL);
    return (map);
}



