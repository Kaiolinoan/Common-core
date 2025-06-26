/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:25:22 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/26 12:21:30 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_data *data)
{
	int size;

	size = px;
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "assets/Gold/gold5.xpm",
			&size, &size);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/player1.xpm", &size, &size);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/Grass/tree.xpm",
			&size, &size);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/Grass/grass.xpm",
			&size, &size);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/Grass/exit.xpm",
			&size, &size);
}

int	put_img(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map->grid[i])
	{
		j = 0;
		while (data->map->grid[i][j])
		{
			if (data->map->grid[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
					j * px, i * px);
			else if (data->map->grid[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.floor,
					j * px, i * px);
            else if (data->map->grid[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.coin,
					j * px, i * px);
            else if (data->map->grid[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player,
					j * px, i * px);
			else if (data->map->grid[i][j] == 'E')
			{
				if (data->map->collectables == 0)
					mlx_put_image_to_window(data->mlx, data->win, data->img.exit,
						j * px, i * px);
				else 
					mlx_put_image_to_window(data->mlx, data->win, data->img.floor,
						j * px, i * px);
			}
			j++;
		}
		i++;
	}
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
