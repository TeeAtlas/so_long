/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/07 17:48:53 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts columns and rows ie: height(row) and width(col)
// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE

void	read_map(t_game *game)
{
	char	*line;
	
	game->fd = open(game->map.map_file, O_RDONLY);
	line =  get_next_line(game->fd);
	printf("what is here:%s\n", line); 
	game->map.rows = 0;
	game->map.h = 0;
	if (!line)
	{
		ft_printf("Error: No file to read\n");
		exit (EXIT_FAILURE);
	}
	printf("2what is here:%s\n", line);
	game->map.str_line = mod_strdup(line);
	printf("3what is here:%s\n", game->map.str_line); 
	game->map.w = maplinelen(line) - 1;
	printf("4what is here:%d\n", game->map.w); 
	free(line);
	while (line)
	{
		game->map.h++;
		line = get_next_line(game->fd);
		if (line)
		{
			game->map.str_line = ft_strjoin(game->map.str_line, line);
		}
	}
	printf("5what is here:%d\n", game->map.h);
	printf("6what is here:%s\n", game->map.str_line); 
	close(game->fd);
}
