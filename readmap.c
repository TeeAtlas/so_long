/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/07 22:27:34 by taboterm         ###   ########.fr       */
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
	game->map.rows = 0;
	game->map.h = 0;
	if (!line)
	{
		ft_printf("Error: No file to read\n");
		exit (EXIT_FAILURE);
	}
	game->map.str_line = mod_strdup(line);
	game->map.w = maplinelen(line) - 1;
	while (line)
	{
		game->map.h++;
		line = get_next_line(game->fd);
		if (line)
		{
			game->map.str_line = mod_join(game->map.str_line, line);
		}
		free(line);
	}
	ft_printf("6what is here:%s\n", game->map.str_line); 
	close(game->fd);
}

// void	read_map_line(t_game *game)
// {
// 	char	*line;
// 	char	*temp;
	
// 	game->fd = open(game->map.map_file, O_RDONLY);
// 	line = get_next_line(game->fd);
// 	while (line)
// 	{
// 		valid_dimensions(line);
// 		temp = ft_strjoin(game->map.str_line, line);
// 		free(game->map.str_line);
// 		game->map.str_line = temp;
// 		free(line);
// 		line = get_next_line(game->fd);
// 	}
// 	ft_printf("line:%s\n", game->map.line);
// 	close(game->fd);
// }