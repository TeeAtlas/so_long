/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:56:06 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/16 22:05:27 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_moves(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		player_up(game);
	if (keycode == KEY_S)
		player_down(game);
	if (keycode == KEY_A)
		player_left(game);
	if (keycode == KEY_D)
		player_right(game);
	// ft_printf("Heyo\n");
	return (EXIT_SUCCESS);
}

void	player_up(t_game *game)
{	
	// CHANGE PLAYER in MAP by WRITING:
	// MAP[i][j] (player) -> MAP[i - 1][j]
	int j;
	int i;
	
	j = game->y;
	i = game->x;
	while (game->map.array[j])
	{
		while (game->map.arrry[j][])
	}
			
		
}

void	player_down(t_game *game)
{
	(void) game;
	
}

void	player_left(t_game *game)
{
	(void) game;
	
}

void	player_right(t_game *game)
{
	(void) game;
	
}
