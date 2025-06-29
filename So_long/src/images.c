/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:25:22 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/29 19:44:03 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_data *data)
{
	int	size;

	size = PX;
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "assets/Gold/gold5.xpm",
			&size, &size);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/player1.xpm", &size, &size);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/Grass/tree.xpm",
			&size, &size);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/Grass/grass.xpm",
			&size, &size);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/Grass/test7.xpm",
			&size, &size);
}

int	put_img(t_data *data)
{
	int	i;
	int	j;
	char *moves;
	//REFAZER O ITOA
	i = 0;
	moves = ft_itoa(data->moves);
	while (data->map->grid[i])
	{
		j = 0;
		while (data->map->grid[i][j])
		{
			mlx_string_put(data->mlx, data->win, 1 * PX, (data->map->height
					- 1.10) * PX, 0x808080, "Moves:");
			mlx_string_put(data->mlx, data->win, 1.6 * PX, (data->map->height
			- 1.10) * PX, 0x808080, moves);
			if (data->map->grid[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, j
					* PX, i * PX);
			else if (data->map->grid[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.floor, j
					* PX, i * PX);
			else if (data->map->grid[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.coin, j
					* PX, i * PX);
			else if (data->map->grid[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player,
					j * PX, i * PX);
			else if (data->map->grid[i][j] == 'E')
			{
				if (data->map->collectables == 0)
					mlx_put_image_to_window(data->mlx, data->win,
						data->img.exit, j * PX, i * PX);
				else
					mlx_put_image_to_window(data->mlx, data->win,
						data->img.floor, j * PX, i * PX);
			}
			j++;
		}
		i++;
	}
	free(moves);
	return (0);
}

void	clean_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.coin);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.floor);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.exit);
}
