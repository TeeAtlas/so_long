/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/28 19:27:16 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*display_tile(t_game *game)
{
	char	*tile_path;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	tile_path = 0;
	if (game->map.array[j][i] == '1')
		tile_path = "images/floor_100x100.xpm";
	ft_printf(tile_path);
// 	else if (game->map.map_file[j][i] == '0')
// 		tile_path = "images/floor_100x100.xpm"; // add new path - try macro
// 	else if (game->map.map_file[j][i])
// 		tile_path = "images/floor_100x100.xpm"; // add new path
// 	else if (game->map.map_file[j][i] == 'C')
// 		tile_path = "images/floor_100x100.xpm"; // add new path
// 	else if (game->map.map_file[j][i]== 'E')
// 		tile_path = "images/floor_100x100.xpm"; // add new path
// 	else if (game->map.map_file[j][i] == 'P')
// 		tile_path = "images/floor_100x100.xpm"; // add new path
	return (tile_path);
}