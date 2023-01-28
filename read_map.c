/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/28 20:44:52 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_maps(t_game *game)
{
	game->map.map_copy = malloc (sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map_copy)
		exit(EXIT_SUCCESS);
}

//counts columns and rows ie: height(row) and width(col)
void	reading_map(t_game *game, char *mapfile)
{
	char	*line;
	
	game->map.rows = 0;
	game->fd = open(mapfile, O_RDONLY);
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



int	display_map(t_game *game)
{
	int		i;
	int		j;
	char	*tile_path;

	i = 0;
	j = 0;
	while (game->map.array[i])
	{
		while (game->map.array[i][j])
		{
			tile_path = display_tile(game);
			game->tile.img = mlx_xpm_file_to_image(game->mlx, tile_path, \
			&game->tile.tile_dimension, &game->tile.tile_dimension);
			mlx_put_image_to_window(game->mlx, game->win, game->tile.img, \
			game->w, game->h);
			game->w = game->w + game->tile.tile_dimension;
			j++;
		}
		j = 0;
		i++;
	}

	return(EXIT_SUCCESS);
}