/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:30:13 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/13 10:48:09 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function converts xpm to pixel which can then be loaded to the window
void	xpm_to_pixel_fl(t_game *game)
{
	game->tile.fl = NULL;
	game->tile.fl = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->x, &game->y);
}

void	xpm_to_pixel_wl(t_game *game)
{
	game->tile.wl = NULL;
	game->tile.wl = mlx_xpm_file_to_image(game->mlx, WALL, &game->x, &game->y);
}

void	xpm_to_pixel_cl(t_game *game)
{
	game->tile.cl = NULL;
	game->tile.cl = mlx_xpm_file_to_image(game->mlx, COLL, &game->x, &game->y);
}