/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/19 10:24:36 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	xpm_to_pixel(t_game *game)
{
	game->tile.fl = NULL;
	game->tile.ex = NULL;
	game->tile.pl = NULL;
	game->tile.wl = NULL;
	game->tile.cl = NULL;
	
	game->tile.fl = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->x, &game->y);
	game->tile.ex = mlx_xpm_file_to_image(game->mlx, EXIT, &game->x, &game->y);
	game->tile.pl = mlx_xpm_file_to_image(game->mlx, PLAY, &game->x, &game->y);
	game->tile.wl = mlx_xpm_file_to_image(game->mlx, WALL, &game->x, &game->y);
	game->tile.cl = mlx_xpm_file_to_image(game->mlx, COLL, &game->x, &game->y);
}

// loads image to window - defined by tile size etc and map co-ordinates
void	load_image(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tile.fl, i * TILE, j * TILE);
			if (game->map.array[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tile.ex, i * TILE, j * TILE);
			if (game->map.array[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->tile.pl, i * TILE, j * TILE);
			if (game->map.array[j][i] == '1')
					mlx_put_image_to_window(game->mlx, game->win, game->tile.wl, i * TILE, j * TILE);
			if (game->map.array[j][i] == 'C')
					mlx_put_image_to_window(game->mlx, game->win, game->tile.cl, i * TILE, j * TILE);	
			i++;
		}
		i = 0;
		j++;
	}			
}