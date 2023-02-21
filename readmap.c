/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/21 17:27:13 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts columns and rows ie: height(row) and width(col)
// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE

int	walled_t_b(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map.h - 1;
	while (game->map.array[i])
	{
		while (i < game->map.w)
		{
			if (game->map.array[0][i] != '1')
			{
				ft_printf("Error: Not walled in\n");
				exit ;
			}
			if (game->map.array[j][i] != '1')
			{
				ft_printf("Error: Not walled in\n");
				exit ;
			}
			i++;
		}
		return (0);
	}
	return (1);
}

void	find_player(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == 'P')
			{				
				game->pl_x = i;
				game->pl_y = j;
			}			
			i++;
		}
		i = 0;
		j++;
	}			
}

void	read_map(t_game *game)
{
	game->fd = open(game->map.map_file, O_RDONLY);
	game->map.line =  get_next_line(game->fd);
	game->map.rows = 0;
	game->map.h = 0;
	if (!game->map.line)
	{
		ft_printf("Error: No file to read\n");
		exit (EXIT_FAILURE);
	}
	game->map.str_line = ft_strdup(game->map.line);
	game->map.w = maplinelen(game->map.line);
	while (game->map.line)
	{
		game->map.h++;
		game->map.line = get_next_line(game->fd);
		if (game->map.line)
		{
			game->map.str_line = ft_strjoin(game->map.str_line, game->map.line);
		}
		free(game->map.line);
	}
	game->map.array = ft_split(game->map.str_line, '\n');
	close(game->fd);
}
