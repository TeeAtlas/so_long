/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/05 23:30:28 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts columns and rows ie: height(row) and width(col)
// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE

void	read_map(t_game *game)
{
	char	*line;
	
	game->map.rows = 0;
	game->fd = open(game->map.map_file, O_RDONLY);
	line =  get_next_line(game->fd);
	if (!line)
	{
		ft_printf("Error: No file to read");
		exit (EXIT_FAILURE);
	}
	game->map.w = maplinelen(line) - 1;
	while (line != 0)
	{
		free(line);
		line = get_next_line(game->fd);
		game->map.rows++;
	}
	game->map.h = game->map.rows;
	close(game->fd);
}



