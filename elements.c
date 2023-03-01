/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:18:38 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/01 20:25:37 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init all pointers to null and all int to 0

void	elements_init(t_game *game)
{
	game->fl_ct = 0;
	game->cl_ct = 0;
	game->pl_ct = 0;
	game->ex_ct = 0;
	game->moves_ct = 0;
	game->coll_count = 0;
	game->reach_ct = 0;
	game->ell_ct = 0;
}


void	elements_list(t_game *game, int i, int j)
{
	if (game->map.array[i][j] == '0')
		game->fl_ct++;
	if (game->map.array[i][j] == 'C')
		game->cl_ct++;
	if (game->map.array[i][j] == 'P')
		game->pl_ct++;
	if (game->map.array[i][j] == 'E') // checking each and incrementing each one
		game->ex_ct++;
}

void	min_max_elements(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < game->map.h - 1)
	{
		j = 0;
		while (j < game->map.w - 1)
		{
			elements_list(game, i , j);
			j++;
		}
		i++;
	}
	game->ell_ct = game->cl_ct + game->ex_ct;
	if (game->fl_ct < 1 || game->cl_ct < 1 || \
			game->ex_ct != 1 || game->pl_ct != 1)
		too_few(game);
}

void	walled_sides(t_game *game)
{
	int	i;
	int	j;

	ft_printf("checking sides\n");
	i = 0;
	j = 0;
	while (i < game->map.h - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		i++;
	}
	i = 0;
	j = game->map.w - 1;
	ft_printf("checking right\n");
	while (i < game->map.h - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		i++;
	}
	ft_printf("sides good\n");
}

void	walled_topbottom(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map.w - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		j++;
	}
	j = 0;
	i = game->map.h - 1;
	while (j < game->map.w - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		j++;
	}
}
