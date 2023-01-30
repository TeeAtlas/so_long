/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/30 17:39:51 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*display_tile(char **mapfile)
{
	char	*tile_path;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	tile_path = 0;
	mapfile = NULL;	

	if (mapfile[y][x] == '1')
		tile_path = "images/floor_100x100.xpm";
	else if (mapfile[y][x] == '0')
		tile_path = "images/floor_100x100.xpm"; // add new path - try macro
	else if (mapfile[y][x])
		tile_path = "images/floor_100x100.xpm"; // add new path
	else if (mapfile[y][x] == 'C')
		tile_path = "images/floor_100x100.xpm"; // add new path
	else if (mapfile[y][x]== 'E')
		tile_path = "images/floor_100x100.xpm"; // add new path
	else if (mapfile[y][x] == 'P')
		tile_path = "images/floor_100x100.xpm"; // add new path
	return (tile_path);
}