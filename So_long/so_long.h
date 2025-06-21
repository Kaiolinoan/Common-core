/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:07:13 by klino-an          #+#    #+#             */
/*   Updated: 2025/06/21 20:01:17 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct map_infos
{
	char	**grid;
	int		width;
	int		height;
	int		collectables;
	int		player_x;
	int		player_y;
}			t_map;

//checkar isso daqui
typedef struct s_data
{
	void		*mlx;
	void		*win; 
	// void		*textures[5]; 
	t_map		*map;
}	t_data;

typedef struct images_infos
{
	void*	mlx;
}			t_image;

int			check_flood_fill(t_map *map, int x, int y, int collectables);
int			check_if_map_is_valid(t_map *map, char *filename);
int			check_collectables(t_map *map);
int			prepare_to_flood(t_map *map);
t_map		*load_map(char *filename);
int			check_player(t_map *map);
int			check_exit(t_map *map);
void		clean_map(t_map *map);

#endif