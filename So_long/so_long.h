/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:07:13 by klino-an          #+#    #+#             */
/*   Updated: 2025/07/01 16:13:12 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define PX 64

typedef struct map_infos
{
	char	**grid;
	int		width;
	int		height;
	int		collectables;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}			t_map;

typedef struct images_infos
{
	void	*temp;
	void	*coin;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
}			t_image;

typedef struct data_infos
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_map	*map;
}			t_data;

int			check_flood_fill(t_map *map, int x, int y, int collectables);
int			check_if_map_is_valid(t_map *map, char *filename);
int			check_collectables(t_map *map);
int			prepare_to_flood(t_map *map);
void		clean_images(t_data *data);
t_map		*load_map(char *filename);
int			check_player(t_map *map);
int			check_exit(t_map *map);
void		clean_map(t_map *map);
int			put_img(t_data *data);
void		images(t_data *data);
int			handle_keys(int keycode, void *param);
int			destroy_game(void *param);

#endif