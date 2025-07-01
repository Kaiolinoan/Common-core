/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:04:16 by klino-an          #+#    #+#             */
/*   Updated: 2025/07/01 18:10:21 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_extension(char *filename)
{
	char	*sub;

	sub = ft_strrchr(filename, '.');
	if (!sub)
		return (0);
	if (ft_strncmp(sub, ".ber", 4) != 0)
		return (0);
	return (1);
}

static int	check_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '1' || map->grid[i][j] == '0'
				|| map->grid[i][j] == 'P' || map->grid[i][j] == 'E'
				|| map->grid[i][j] == 'C')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_format(t_map *map)
{
	int	i;
	int	len;

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

static int	check_walls(t_map *map)
{
	int	i;
	int	j;
	int	imax;
	int	jmax;

	i = 0;
	j = 0;
	imax = map->height - 1;
	jmax = map->width - 1;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != '1' && (i == 0 || j == 0 || i == imax
					|| j == jmax))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_map_is_valid(t_map *map, char *filename)
{
	if (check_extension(filename) == 0)
		return (ft_printf("Erro:\nFile is not supported\n"), 0);
	if (check_format(map) == 0)
		return (ft_printf("Erro:\nInvalid Format\n"), 0);
	if (check_characters(map) == 0)
		return (ft_printf("Erro:\nInvalid Character\n"), 0);
	if (check_walls(map) == 0)
		return (ft_printf("Erro:\nInvalid Map\n"), 0);
	if (check_player(map) == 0)
		return (ft_printf("Erro:\nInvalid Player\n"), 0);
	if (check_exit(map) == 0)
		return (ft_printf("Erro:\nInvalid Exit\n"), 0);
	if (check_collectables(map) == 0)
		return (ft_printf("Erro:\nInvalid Collectable\n"), 0);
	if (prepare_to_flood(map) == 0)
		return (ft_printf("Erro:\nInvalid Path\n"), 0);
	return (1);
}
