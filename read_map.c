/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/27 20:01:05 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (game->map.array[i])
	{
		while (game->map.array[i][j])
		{
			if (game->map.array[i][j] == 'P')
			{				
				game->pl_x = j;
				game->pl_y = i;
			}			
			j++;
		}
		j = 0;
		i++;
	}			
}

void	read_map(t_game *game)
{
	char	*temp;

	game->map.h = 0;
	game->map.rows = 0;
	game->fd = open(game->map.map_file, O_RDONLY);
	game->map.line =  get_next_line(game->fd);
	if (!game->map.line)
		no_file(game);
	game->map.w = maplinelen(game->map.line);
	game->map.str_line = ft_strdup(game->map.line);
	while (game->map.line)
	{
		game->map.h++;
		if (game->map.h > 1)
		{
			temp = ft_strjoin(game->map.str_line, game->map.line);
			free(game->map.str_line);
			game->map.str_line = temp;
		}
		free(game->map.line);
		game->map.line = get_next_line(game->fd);
	}
	game->map.array = ft_split(game->map.str_line, '\n');
	game->map.array_cpy = ft_split(game->map.str_line, '\n');
	close(game->fd);
}
