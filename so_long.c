/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:14 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/11 02:53:06 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void*mlx_init connects my software to display of OS, void*mlx_new_window, a 
funciton that opens a new window on the display. receives previously obtained 
pointer w, h, and title and displays window. int mlx_loop - waits for keyboard and
mouse input in the popped window. also redraws part of the window.
cc -framework OpenGL -framework AppKit the_function.c minilibx_opengl_20191021/libmlx.a */

int	goodbye(int keycode, t_param *param)
{
	(void)param;
	if (keycode == KEY_ESC)
		exit(0);
	// {
	// 	printf("keycode: %d\n", keycode);
	// 	printf("x keycode equals: %d\n", param->x);
	// 	printf("y keycode equals: %d\n", param->y);
	// }
	return(0);
}

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	*game;
	t_param	param;
	
	(void) argc;
	game = NULL;
	game = (t_game *) malloc (sizeof(t_game));
	game->map.map_file = argv[1];
	if (filecheck(game) == 0)
		return (EXIT_FAILURE);
	//read_map(game);

	// param_init(&param);
	// mlx_ptr = (void *) malloc (sizeof(void));
	game->mlx.mlx_ptr = mlx_init();
	// win_ptr = (void *) malloc (sizeof(void));
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, 800, 450, "So Long and Thanks!");
	game->mlx.img_list = (t_img_lst *)malloc(sizeof(t_img_lst));
	// t_img	*new;
	
	//new = (t_img *)malloc(sizeof(t_img));
	//new->img_ptr = mlx_new_image(game->mlx.mlx_ptr, 100, 100);
	//new->next = NULL;
	//game->mlx.img_list->first = new;
	
	//new = (t_img *)malloc(sizeof(t_img));
	// new->img_ptr = mlx_new_image(game->mlx.mlx_ptr, 100, 100);
	// new->next = NULL;
	// game->mlx.img_list->first->next = new;	

	t_tile *floor;
	floor = (t_tile *)malloc(sizeof(t_tile));
	floor->tile_width = 50;
	floor->tile_height = 50;
	floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./images/floor_100x100.xpm", &floor->tile_width, &floor->tile_height);
//	game->floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./images/floor_100x100.xpm", &game->img_width + 200, &game->img_height + 200);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, floor, 100, 100);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, floor, 0, 0);
	mlx_key_hook(game->mlx.win_ptr, &goodbye, &param);
	mlx_loop(game->mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}