/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/26 18:16:35 by taboterm         ###   ########.fr       */
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

int	is_valid_path(t_game *game)
{
	int	x;
	int	y;

	x = game->pl_x;
	y = game->pl_y;
	reachables(game, x, y);
	if (game->ell_ct != game->reach_ct)
	{
		ft_printf("Error: No Valid Path\n");
		return (1);
	}
	else if (game->ell_ct == game->reach_ct)
	{
		ft_printf("Is Valid Path\n");
		return (0);
	}
	return (0);
}

int path_check(t_game *game)
{
	int	i;

	i = 0;
	i += is_valid_path(game);
	if (i == 0)
		return (0);
	return (1);		
}