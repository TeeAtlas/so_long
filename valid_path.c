/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/25 18:59:12 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	reachables(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == '1')
		return ;
	if (game->map.array[y][x] == 'C')
		game->reach_ct++;
	if (game->map.array[y][x] == 'E')
		game->reach_ct++;
	game->map.array[y][x] = '1';
	reachables(game, x, y + 1);
	reachables(game, x, y - 1);
	reachables(game, x + 1, y);
	reachables(game, x - 1, y);
}

int	valid_path(t_game *game)
{
	int	x;
	int	y;

	x = game->pl_x;
	y = game->pl_y;
	reachables(game, x,y);
	if (game->ell_ct != game->reach_ct)
	{
		ft_printf("Error: No Valid Path\n");
		return (1);
	}
	return (0);
}