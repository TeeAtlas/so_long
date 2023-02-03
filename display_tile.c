/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/03 15:45:21 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/* xpm files to pixels */
void	image_xpm_to_map(t_game *game)
{
	game->tile.fl = mlx_xpm_file_to_img(game->mlx, FLOOR,\
									&game->map.w, &game->map.h);
}

/* images to the map */
void	load_image(t_game *game, int i, int j)
{
	size_t	x;
	size_t	y;

	x = i * TILE;
	y = j * TILE;
	if (game->map.map_file[i][j] =='1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->tile.fl, x, y);
	
}