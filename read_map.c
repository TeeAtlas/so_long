/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/30 17:31:15 by taboterm         ###   ########.fr       */
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
void	cols_rows(t_game *game)
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

void	read_map_array(t_game *game)
{
	game->fd = open(game->map.map_file, O_RDONLY);
	game->map.str = malloc (sizeof(char));
	while (game->map.str)
	{
		game->map.str = get_next_line(game->fd);
		if(game->map.str)
			game->map.str_2 = ft_strjoin(game->map.str_2, game->map.str);
	}
	printf("map str: \n%s\n", game->map.str_2);
}

// int	display_map(t_game *game, char *mapfile)
// {
// 	int		i;
// 	int		j;
// 	char	*tile_path;
	
	
// 	printf("map");
// 	j = 0;
// 	game->map.w = 0;
// 	while (game->map.rows)
// 	{
// 		printf("what is here: %d", game->map.rows);
// 		i = 0;
// 		game->map.h = 0;
// 		while (mapfile[i][j] != '\n' &&  mapfile[i][j] != '\0')
// 		{
// 			tile_path = display_tile(game);
// 			game->tile.img = mlx_xpm_file_to_image(game->mlx, tile_path, \
// 			&game->tile.tile_dimension, &game->tile.tile_dimension);
// 			mlx_put_image_to_window(game->mlx, game->win, game->tile.img, \
// 			game->map.w, game->map.h);
// 			game->map.w += game->tile.tile_dimension;
// 			j++;
// 		}
// 		i = 0;
// 		i++;
// 		game->map.h += game->tile.tile_dimension;
// 	}
// }