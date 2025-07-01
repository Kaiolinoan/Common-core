/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:25:22 by klino-an          #+#    #+#             */
/*   Updated: 2025/07/01 18:56:09 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	images(t_data *data)
{
	int	size;

	size = PX;
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "assets/Gold/gold5.xpm",
			&size, &size);
	data->img.player[0] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w1.xpm", &size, &size);
	data->img.player[1] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w2.xpm", &size, &size);
	data->img.player[2] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w3.xpm", &size, &size);
	data->img.player[3] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w4.xpm", &size, &size);
	data->img.player[4] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w5.xpm", &size, &size);
	data->img.player[5] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w6.xpm", &size, &size);
	data->img.player[6] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w7.xpm", &size, &size);
	data->img.player[7] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w8.xpm", &size, &size);
	data->img.player[8] = mlx_xpm_file_to_image(data->mlx,
			"assets/Player/walking/w9.xpm", &size, &size);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/Grass/tree.xpm",
			&size, &size);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/Grass/grass.xpm",
			&size, &size);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/Grass/test7.xpm",
			&size, &size);
}

int	put_img(t_data *data)
{
	int		i;
	int		j;
	char	*moves;
	int frame_count;

	i = 0;
	frame_count = 0;
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
			while (data->map->grid[i][j] == 'P' && frame_count <= 2)
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img.player[frame_count],
						j * PX, i * PX);
				// usleep(10000);
				frame_count++;
			}
			frame_count = 0;
			if (data->map->grid[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, j
					* PX, i * PX);
			else if (data->map->grid[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.floor, j
					* PX, i * PX);
			else if (data->map->grid[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.coin, j
					* PX, i * PX);
	
			if (data->map->grid[i][j] == 'E')
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

/* int	game_loop(t_data *data)
{
	int coin_frame;
	int player_frame;

	data->anim->frame_count++;

	coin_frame = (data->anim->frame_count / 8);
} */