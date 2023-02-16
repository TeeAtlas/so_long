/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:14 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/16 11:51:04 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void*mlx_init connects my software to display of OS, void*mlx_new_window, a 
funciton that opens a new window on the display. receives previously obtained 
pointer w, h, and title and displays window. int mlx_loop - waits for keyboard and
mouse input in the popped window. also redraws part of the window.
cc -framework OpenGL -framework AppKit the_function.c minilibx_opengl_20191021/libmlx.a */

//initializing game and establishing window size
void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	game->tile.tile_dimension = TILE;
	read_map(game);
	game->win = mlx_new_window(game->mlx, game->map.w * TILE, \
	game->map.h * TILE, "Shadow of Dr. Manhattan");
	xpm_to_pixel_fl(game);
	xpm_to_pixel_ex(game);
	xpm_to_pixel_pl(game);
	xpm_to_pixel_wl(game);
	xpm_to_pixel_cl(game);
	load_image(game);
}

int	close_window(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return(EXIT_SUCCESS);
}

void	arg_check(int argc)
{
	if (argc !=2)
	{
		ft_printf("System Failure: no map to the stars!\n", argc);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{	
	t_game		*game;
	
	arg_check(argc);
	game = NULL;
	game = (t_game *) malloc (sizeof(t_game));
	game->map.map_file = argv[1];
	if (filecheck(game) == 0)
		return (EXIT_FAILURE);
	initialize_game(game);
	mlx_key_hook(game->win, &close_window, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}