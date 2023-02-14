/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/14 12:01:03 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

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
			// if (game->map.array[j][i] == '1')
			// 		mlx_put_image_to_window(game->mlx, game->win, game->tile.wl, i * TILE, j * TILE);
			// if (game->map.array[j][i] == 'C')
			// 		mlx_put_image_to_window(game->mlx, game->win, game->tile.cl, i * TILE, j * TILE);	
			i++;
		}
		i = 0;
		j++;
	}			
}