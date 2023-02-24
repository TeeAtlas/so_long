/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:56:06 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/24 16:43:08 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int player_moves(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		player_up(game);
	if (keycode == KEY_S)
		player_down(game);
	if (keycode == KEY_A)
		player_left(game);
	if (keycode == KEY_D)
		player_right(game);
	return (EXIT_SUCCESS);
}

void	player_up(t_game *game)
{	
	game->coll_count = 0;
	if (game->map.array[game->pl_y - 1][game->pl_x] != '1')
	{
		if (game->map.array[game->pl_y - 1][game->pl_x] == 'C')
			game->coll_count = game->coll_count - 1;
		// if (game->map.array[game->pl_y - 1][game->pl_x] == 'E' && game->coll_count == 0)
		// {
		// 	game->moves_ct++;
		// 	game_over(game);
		// }
		if (game->map.array[game->pl_y - 1][game->pl_x] != 'E')
		{
			game->map.array[game->pl_y][game->pl_x] = '0';
			game->pl_y = game->pl_y - 1;
			game->map.array[game->pl_y][game->pl_x] = 'P';
			game->moves_ct++;
			ft_printf("Steps: %d\n", game->moves_ct);
			load_image(game);
		}
	}
}

void	player_down(t_game *game)
{
	game->coll_count = 0;
	if (game->map.array[game->pl_y + 1][game->pl_x] != '1')
	{
		if (game->map.array[game->pl_y + 1][game->pl_x] == 'C')
			game->coll_count = game->coll_count + 1;
		// if (game->map.array[game->pl_y + 1][game->pl_x] == 'E' && game->coll_count == 0)
		// {
		// 	game->moves_ct++;
		// 	game_over(game);
		// }
		if (game->map.array[game->pl_y + 1][game->pl_x] != 'E')
		{
			game->map.array[game->pl_y][game->pl_x] = '0';
			game->pl_y = game->pl_y + 1;
			game->map.array[game->pl_y][game->pl_x] = 'P';
			game->moves_ct++;
			ft_printf("Steps: %d\n", game->moves_ct);
			load_image(game);
		}
	}
}

void	player_left(t_game *game)
{

	if (game->map.array[game->pl_y][game->pl_x - 1] != '1')
	{	
		if (game->map.array[game->pl_y][game->pl_x - 1] == 'C')
			game->coll_count = game->coll_count + 1;
		// if (game->map.array[game->pl_y][game->pl_x - 1] == 'E' && game->coll_count == 0)
		// {
		// 	game->moves_ct++;
		// 	game_over(game);
		// }
		if (game->map.array[game->pl_y][game->pl_x - 1] != 'E')
		{	
			game->map.array[game->pl_y][game->pl_x] = '0';
			game->pl_x = game->pl_x - 1;
			game->map.array[game->pl_y][game->pl_x] = 'P';
			game->moves_ct++;
			ft_printf("Steps: %d\n", game->moves_ct);
			load_image(game);
		}
	}
}

void	player_right(t_game *game)
{
	game->coll_count = 0;
	if (game->map.array[game->pl_y][game->pl_x + 1] != '1')
	{
		if (game->map.array[game->pl_y][game->pl_x + 1] == 'C')
			game->coll_count = game->coll_count + 1;
		// if (game->map.array[game->pl_y][game->pl_x + 1] == 'E' && game->coll_count == 0)
		// {
		// 	game->moves_ct++;
		// 	game_over(game);
		// }
		if (game->map.array[game->pl_y][game->pl_x + 1] != 'E')
		{
			game->map.array[game->pl_y][game->pl_x] = '0';
			game->pl_x = game->pl_x + 1;
			game->map.array[game->pl_y][game->pl_x] = 'P';
			game->moves_ct++;
			ft_printf("Steps: %d\n", game->moves_ct);
			load_image(game);
		}
	}
}
