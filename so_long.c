/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:14 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/25 21:59:42 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void*mlx_init connects my software to display of OS, void*mlx_new_window, a 
funciton that opens a new window on the display. receives previously obtained 
pointer w, h, and title and displays window. int mlx_loop - waits for keyboard and
mouse input in the popped window. also redraws part of the window.
cc -framework OpenGL -framework AppKit the_function.c minilibx_opengl_20191021/libmlx.a */


void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	game->bsize = TILE_SIZE;
	game->mlx = mlx_new_window \
	(game->mlx, 1000, 500, "Shadow of Dr. Manhattan");
	//will have to create function for counting columns and rows ex:
	//game->window = mlx_new_window(game->mlx, game->map_columns_count * \
	//game->tile_dimension, game->map_rows_count \
	//* game->tile_dimension, "so_long");
}

int	close_window(int keycode, t_param *param)
{
	(void)param;
	if (keycode == KEY_ESC)
		exit(0);
	// {
	// 	printf("keycode: %d\n", keycode);
	// }
	return(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{	
    t_game		*game;
    // char    	*map_filedata;
	t_param		param;
	
	(void) argc;
	game = NULL;
	game = (t_game *) malloc (sizeof(t_game));
    //opening file map and grab all information from .ber file (done)
	game->map.map_file = argv[1];
	if (filecheck(game) == 0)
		return (EXIT_FAILURE);
	initialize_game(game);
    //path finder
	//find player
	// add_tiles(game);
    // draw_map(game);
	mlx_key_hook(game->mlx, &close_window, &param);
	mlx_loop(game->mlx);
    return (EXIT_SUCCESS);
}