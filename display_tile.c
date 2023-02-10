/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/10 18:39:43 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

// /* xpm files to pixels */
// void	image_xpm_to_map(t_game *game)
// {
// 	game->tile.fl = mlx_xpm_file_to_image(game->mlx, FLOOR, \
// 									&game->map.w, &game->map.h);
// }

/* images to the map */
void	load_image(t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	x = i * TILE;
	y = j * TILE;
	game->tile.fl = NULL;
	game->tile.fl = mlx_xpm_file_to_image(game->mlx, "./images/floor_100x100.xpm", \
									&x, &y);
	ft_printf("HERE3 w: %i h: %i img pointer %p\n", x, y, game->tile.fl);
	if (game->map.array[j][i] == '1')
	{
		ft_printf("In if w: %i h: %i \n", game->map.w, game->map.h);
		mlx_put_image_to_window(game->mlx, game->win, game->tile.fl, 0, 0);
	}
	
}