/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/11 21:11:22 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	xpm_to_pixel(t_game *game)
{
	game->fl = NULL;
	game->ex = NULL;
	game->pl = NULL;
	game->wl = NULL;
	game->cl = NULL;
	game->fl = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->x, &game->y);
	game->ex = mlx_xpm_file_to_image(game->mlx, EXIT, &game->x, &game->y);
	game->pl = mlx_xpm_file_to_image(game->mlx, PLAY, &game->x, &game->y);
	game->wl = mlx_xpm_file_to_image(game->mlx, WALL, &game->x, &game->y);
	game->cl = mlx_xpm_file_to_image(game->mlx, COLL, &game->x, &game->y);
}

void	load_image(t_game *game)
{
	load_image_1(game);
	load_image_2(game);
}

void	load_image_1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == '0')
				mlx_put_image_to_window(game->mlx, \
					game->win, game->fl, i * TILE, j * TILE);
			if (game->map.array[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, \
					game->win, game->ex, i * TILE, j * TILE);
			i++;
		}
		i = 0;
		j++;
	}
}

// loads image to window - defined by tile size etc and map co-ordinates
void	load_image_2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, \
					game->win, game->pl, i * TILE, j * TILE);
			if (game->map.array[j][i] == '1')
				mlx_put_image_to_window(game->mlx, \
					game->win, game->wl, i * TILE, j * TILE);
			if (game->map.array[j][i] == 'C')
				mlx_put_image_to_window(game->mlx, \
					game->win, game->cl, i * TILE, j * TILE);
			i++;
		}
		i = 0;
		j++;
	}			
}
