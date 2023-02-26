/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:39:07 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/26 15:12:16 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// destroys window 
int destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (EXIT_SUCCESS);
}

void	no_file(t_game *game)
{
	ft_printf("Error: No file to read\n");
	free_game(game);
	exit (EXIT_FAILURE);
}

void	game_over(t_game  *game)
{
	ft_printf("You're out! You did it in %d moves.\n", game->moves_ct);
	free_game(game);
	exit(EXIT_FAILURE);
}