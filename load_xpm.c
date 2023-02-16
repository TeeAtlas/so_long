/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:30:13 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/16 20:00:38 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function converts xpm to pixel which can then be loaded to the window

// void	xpm_to_pixel(t_game *game)
// {
// 	game->tile.fl = NULL;
// 	game->tile.ex = NULL;
// 	game->tile.pl = NULL;
// 	game->tile.wl = NULL;
// 	game->tile.cl = NULL;
	
// 	game->tile.fl = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->x, &game->y);
// 	game->tile.ex = mlx_xpm_file_to_image(game->mlx, EXIT, &game->x, &game->y);
// 	game->tile.pl = mlx_xpm_file_to_image(game->mlx, PLAY, &game->x, &game->y);
// 	game->tile.wl = mlx_xpm_file_to_image(game->mlx, WALL, &game->x, &game->y);
// 	game->tile.cl = mlx_xpm_file_to_image(game->mlx, COLL, &game->x, &game->y);
// }