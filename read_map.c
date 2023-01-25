/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/25 21:42:03 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_maps(t_game *game)
{
	game->map.map_file = malloc (sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map_file)
		exit(EXIT_SUCCESS);
	game->map.map_copy = malloc (sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map_copy)
		exit(EXIT_SUCCESS);
}

//counts columns and rows ie: height(row) and width(col)
void	read_map(t_game *game)
{
	char	*line;
	
	game->map.rows = 0;
	game->fd = open(game->map.map_file, O_RDONLY);
	line = get_next_line(game->fd);
	if (!line)
	{
		ft_printf("No file to read");
		exit (EXIT_SUCCESS);
	}
	free (line);
	game->map.w = ft_strlen(line) - 1;
	while (line != 0)
	{
		line = get_next_line(game->fd);
		game->map.rows++;
		free(line);
	}
	game->map.h = game->map.rows;
	close(game->fd);
	malloc_maps(game);
}

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.array[i])
	{
		while (game->map.array[i][j])
		{
			if (game->map.array[i][j] == '1')
				img_to_map(game, game->tile.fl, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return(0);
}

