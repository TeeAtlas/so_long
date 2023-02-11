/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/11 12:00:26 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	load_image(t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	
	i = 0;
	j = 0;
	game->tile.fl = NULL;
	game->tile.fl = mlx_xpm_file_to_image(game->mlx, "./images/floor_100x100.xpm", \
									&x, &y);
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == '0')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->tile.fl, i * 100, j * 100);
				}	
			// else if (game->map.array[j][i] == 'C')
			// 	{
			// 		mlx_put_image_to_window(game->mlx, game->win, game->tile.ch, i * 100, j * 100);
			// 	}
			i++;
		}
		i = 0;
		j++;
	}			
}