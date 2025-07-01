/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:17:55 by klino-an          #+#    #+#             */
/*   Updated: 2025/07/01 18:13:13 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	count_lines(char *filename)
{
	size_t	count;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Erro"), -1);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (close(fd), count);
}

static t_map	*fill_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Erro:\n"), NULL);
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->grid[i++] = line;
	}
	map->width = ft_strlen(map->grid[0]);
	map->grid[i] = NULL;
	return (close(fd), map);
}

t_map	*load_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (free(map), NULL);
	if (count_lines(filename) == -1)
		return (free(map), NULL);
	map->height = count_lines(filename);
	if (map->height <= 2)
		return (free(map), NULL);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (free(map->grid), free(map), NULL);
	map = fill_map(map, filename);
	if (!map)
		return (ft_printf("Erro ao preencher o mapa!"), NULL);
	if (check_if_map_is_valid(map, filename) == 0)
		return (clean_map(map), NULL);
	return (map);
}

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
	if (map)
		free(map);
}
