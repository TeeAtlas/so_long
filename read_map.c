/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/01 14:41:10 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_maps(t_game *game)
{
	game->map.map_copy = malloc (sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map_copy)
		exit(EXIT_SUCCESS);
}

void	read_map_array(t_game *game)
{
	game->fd = open(game->map.map_file, O_RDONLY);
	game->map.str = malloc (sizeof(char));
	game->map.str_2 = malloc (sizeof(char));
	while (game->map.str)
	{
		game->map.str = get_next_line(game->fd);
		if(game->map.str)
			game->map.str_2 = ft_strjoin(game->map.str_2, game->map.str);
	}
	printf("map str: \n%s\n", game->map.str_2);
}

//do I need to strjoin the array?

//counts columns and rows ie: height(row) and width(col)
void	count_col_row(t_game *game)
{
	char	*line;
	
	game->map.rows = 0;
	game->fd = open(game->map.map_file, O_RDONLY);
	line =  get_next_line(game->fd);
	if (!line)
	{
		ft_printf("Error: No file to read");
		exit (EXIT_SUCCESS);
	}
	game->map.w = ft_strlen(line) - 1;
	while (line != 0)
	{
		free(line);
		line = get_next_line(game->fd);
		game->map.rows++;
	}
	game->map.h = game->map.rows;
	close(game->fd);
	malloc_maps(game);
}



