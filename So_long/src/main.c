/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:02 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/21 20:01:17 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	reload_player(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);

	ft_printf("Antes:\n");
	ft_printf("%d\n", map->player_x);
	ft_printf("%d\n", map->player_y);
	//pensar sobre os 1 e o E
	map->grid[map->player_y][map->player_x] = '0';
	map->player_x = x;
	map->player_y = y;
	ft_printf("Depois:\n");
	ft_printf("%d\n", map->player_x);
	ft_printf("%d\n", map->player_y);
	if (map->grid[y][x] == '1')
		return (0);
	return (1);
}

int	destroy_game(void *param)
{
	t_data	*data;

	data = param;
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	return (0);
}

int	handle_keys(int keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode == XK_w || keycode == XK_Up)
		return (reload_player(data->map, data->map->player_x,
				data->map->player_y + 1), 0);
	else if (keycode == XK_a || keycode == XK_Left)
		return (reload_player(data->map, data->map->player_x - 1,
				data->map->player_y), 0);
	else if (keycode == XK_s || keycode == XK_Down)
		return (reload_player(data->map, data->map->player_x,
				data->map->player_y - 1), 0);
	else if (keycode == XK_d || keycode == XK_Right)
		return (reload_player(data->map, data->map->player_x + 1,
				data->map->player_y), 0);
	else if (keycode == XK_Escape)
		return (destroy_game(data), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	(void)argc;
	// t_map	*map;
	// if (!map)
	// 	ft_printf("erro ao dar load no mapa");
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map = load_map(argv[1]);
	if (!data->map)
		return (0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, 600, 400, "ola");
	if (!data->win)
		return (free(data->win), 0);
	// mlx_loop_hook();
	mlx_key_hook(data->win, handle_keys, data);
	mlx_hook(data->win, DestroyNotify, KeyPressMask, destroy_game, data);
	mlx_loop(data->mlx);
}

// if (argc != 2)
/* 		return (ft_printf("Argumento invalido!"));
ft_printf("---%d---\n", check_if_map_is_valid(map, argv[1]));
free(map->grid);
free(map); */