/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/25 21:48:01 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	load_fl(t_game *game)
{
	game->tile.fl = (t_tile *)malloc(sizeof(t_tile));
	game->tile.fl = mlx_xpm_file_to_image(game->mlx, FLOOR_TILE, \
	&game->tile.w, &game->tile.h);
	if (!game->tile.fl)
		image_fail(game);
}

void	add_tiles(t_game *game)
{
	load_fl(game);
}

void	img_to_map(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, j * 100, i * 100);
}