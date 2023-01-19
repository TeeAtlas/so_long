/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:57 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/13 18:42:45 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{	
	t_game *game;
	
	game->floor = (t_game *)malloc(sizeof(t_game));
	game->tile_width = 50;
	game->tile_height = 50;
	game->floor = mlx_xpm_file_to_image(game->mlx, "./images/floor.xpm", \
	&game->tile_width, &game->tile_height);
}
