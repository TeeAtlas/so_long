/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:18:38 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/22 17:38:18 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	min_char_1(t_game *game)
{
	int	i;
	int	j;
	
	game->fl_ct = 0;
	game->cl_ct = 0;
	game->pl_ct = 0;
	game->ex_ct = 0;
	i = 0;
	j = 0;
	while (i < game->map.h - 1)
	{
		j = 0;
		while (j < game->map.w - 1)
		{
			if (game->map.array[i][j] == '0')
				game->fl_ct++;
			if (game->map.array[i][j] == 'C')
				game->cl_ct++;
			if (game->map.array[i][j] == 'P')
				game->pl_ct++;
			if (game->map.array[i][j] == 'E')
				game->ex_ct++;
			j++;
		}
		i++;
	}
	if (game->fl_ct < 1 || game->cl_ct < 1 || game->ex_ct != 1 || game->pl_ct != 1)
		too_few(game);
}

void	walled_sides(t_game *game)
{
	int	i;
	int	j;
	
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
	while (i < game->map.h - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		i++;
	}
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