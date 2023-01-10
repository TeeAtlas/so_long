/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:14 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/10 13:30:23 by taboterm         ###   ########.fr       */
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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_game	*game;
	t_param	param;
	
	game = NULL;
	game = (t_game *) malloc (sizeof(t_game));
	// param_init(&param);
	// mlx_ptr = (void *) malloc (sizeof(void));
	mlx_ptr = mlx_init();
	// win_ptr = (void *) malloc (sizeof(void));
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "So Long and Thanks!");
	game->img_ptr = mlx_new_image(mlx_ptr, 1920, 1080);
	game->addr_ptr = mlx_get_data_addr(game->img_ptr, &game->bits_per_pixel, &game->line_length,
									&game->endian);
	game->floor = mlx_xpm_file_to_image(mlx_ptr, "./images/floor_100x100.xpm", &game->img_width, &game->img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, game->floor, 0, 0);
	
	mlx_key_hook(win_ptr, &goodbye, &param);
	mlx_loop(mlx_ptr);
	return (0);
}