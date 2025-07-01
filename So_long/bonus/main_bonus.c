/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/07/01 15:35:51 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy_game(void *param)
{
	t_data	*data;

	data = param;
	clean_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_map(data->map);
	free(data);
	exit(-1);
	return (0);
}
int	check_player2(t_data *data)
{
	if (data->map->grid[data->map->player_y][data->map->player_x] == 'C')
	{
		data->map->collectables--;
		return (0);
	}
	return (1);
}

int	reload_player(t_data *data, int x, int y)
{
	char		next;
	int			i;

	next = data->map->grid[y][x];
	if (next == 'C')
		data->map->collectables--;
	if (next == 'E')
		if (data->map->collectables == 0)
			return (destroy_game(data));
	if (data->map->grid[y][x] == '1')
		return (0);
	if (next != 'E')
	{
		data->map->grid[data->map->player_y][data->map->player_x] = '0';
		if (data->map->player_y == data->map->exit_y
			&& data->map->player_x == data->map->exit_x)
			data->map->grid[data->map->player_y][data->map->player_x] = 'E';
		data->map->player_x = x;
		data->map->player_y = y;
		data->map->grid[data->map->player_y][data->map->player_x] = 'P';

	}
	else if (next == 'E' && data->map->collectables != 0)
	{
		data->map->grid[data->map->player_y][data->map->player_x] = '0';
		data->map->player_x = x;
		data->map->player_y = y;
		data->map->grid[data->map->player_y][data->map->player_x] = 'P';
	}
	i = 0;
	while (data->map->grid[i])
		ft_printf("%s\n", data->map->grid[i++]);
	ft_printf("col:%d\n", data->map->collectables);
	i = 0;
	ft_printf("%c\n", next);
	return (1);
}

int	handle_keys(int keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode == XK_w || keycode == XK_Up)
		return (reload_player(data, data->map->player_x, data->map->player_y
				- 1), 0);
	else if (keycode == XK_a || keycode == XK_Left)
		return (reload_player(data, data->map->player_x - 1,
				data->map->player_y), 0);
	else if (keycode == XK_s || keycode == XK_Down)
		return (reload_player(data, data->map->player_x, data->map->player_y
				+ 1), 0);
	else if (keycode == XK_d || keycode == XK_Right)
		return (reload_player(data, data->map->player_x + 1,
				data->map->player_y), 0);
	else if (keycode == XK_Escape)
		return (destroy_game(data), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf("Invalid Argument!"));
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map = load_map(argv[1]);
	if (data->map == NULL)
		return (free(data), ft_printf("Erro:\nFailed to load the map\n"), 0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->map->width * PX,
			data->map->height * PX, "ola");
	if (!data->win)
		return (free(data->win), 0);
	// add o counter de moves
	ft_printf("Exit_Y:%d\n", data->map->exit_y);
	ft_printf("Exit_X:%d\n", data->map->exit_x);
	images(data);
	mlx_loop_hook(data->mlx, put_img, data);
	mlx_key_hook(data->win, handle_keys, data);
	mlx_hook(data->win, DestroyNotify, KeyPressMask, destroy_game, data);
	mlx_loop(data->mlx);
	return (0);
}
