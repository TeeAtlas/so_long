/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/01 15:01:52 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	image_to_map(t_game *game)
{
	int h;
	int w;

	h = 0;
	game->h = game->map.h;
	game->w = game->map.w;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			if (game->map.str_2[h * game->w + w] == '1')
				mlx_xpm_file_to_image(game->mlx,\
	 			"images/floor_100x100.xpm", &game->tile.tile_dimension, &game->tile.tile_dimension);
			w++;
		}
		h++;
	}
}