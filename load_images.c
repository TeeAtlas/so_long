/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/22 21:45:17 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	load_images(t_game *game)
{
	game->tile.fl = (t_tile *)malloc(sizeof(t_tile));

	game->tile.fl = mlx_xpm_file_to_image(game->mlx, ".images/floor_100x100.xpm", \
	&game->tile.w, &game->tile.h);
	if (!game->tile.fl)
		image_fail(game);
	
}

void	img_to_win(t_game *game, void *img)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	mlx_put_image_to_window(game->mlx, game->win, img, j * 100, i * 100);
}