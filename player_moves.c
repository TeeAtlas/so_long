/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:56:06 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/17 17:40:58 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int player_moves(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		player_up(game);
	ft_printf("Hello1\n");
	// if (keycode == KEY_S)
	// 	player_down(game);
	// if (keycode == KEY_A)
	// 	player_left(game);
	// if (keycode == KEY_D)
	// 	player_right(game);
	// ft_printf("Heyo\n");
	return (EXIT_SUCCESS);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	game->pl_x = j;
	game->pl_y = i;
	
	while (game->map.array[game->pl_y])
	{
		while (game->map.array[game->pl_y][game->pl_x] == 'P')
		{
			
		}
	}
	
}

void	player_up(t_game *game)
{	
	// CHANGE PLAYER in MAP by WRITING:
	// MAP[i][j] (player) -> MAP[i - 1][j]
	ft_printf("Hello2\n");
	ft_printf("here %d\n", game->pl_y);
	find_player(game);
	if (game->map.array[game->pl_y - 1][game->pl_x] == '1')
		return ;
	
}


// void	player_down(t_game *game)
// {
// 	(void) game;
	
// }

// void	player_left(t_game *game)
// {
// 	(void) game;
	
// }

// void	player_right(t_game *game)
// {
// 	(void) game;
	
// }


// to move up
// example:
// if 'P' = game->map.array[1][7]
// and to move up 
// if 'O' = game->map.array[0][7]
// co-ordinates are game->map.array[]