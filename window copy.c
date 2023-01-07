/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:14 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/07 18:30:34 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
#include "./minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/* void*mlx_init connects my software to display of OS, void*mlx_new_window, a 
funciton that opens a new window on the display. receives previously obtained 
pointer w, h, and title and displays window. int mlx_loop - waits for keyboard and
mouse input in the popped window. also redraws part of the window.*/

// typedef	struct	s_game
// {
// 	void	*img_ptr;
// 	char	*addr_ptr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
	
// }		t_game;

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

# define KEY_ESC		53

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	goodbye(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		printf("keycode: %d\n", keycode);
		printf("x keycode equals: %d\n", param->x);
		printf("y keycode equals: %d\n", param->y);
	}
	return(0);
}

void	put_pixel(t_game *game, int x, int y, int colour)
{
	char	*dst;

	dst = game->addr_ptr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_game	*game;
	t_param	param;
	
	game = NULL;
	game = malloc (sizeof(game));
	param_init(&param);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "So Long and Thanks!");

	game->img_ptr = mlx_new_image(mlx_ptr, 1920, 1000);
	game->addr_ptr = mlx_get_data_addr(game->img_ptr, &game->bits_per_pixel, &game->line_length,
									&game->endian);
	put_pixel(game->img_ptr, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, game->img_ptr, 70, 70);
	mlx_hook(win_ptr, 3, 0, &goodbye, &param);
	

	mlx_loop(mlx_ptr);
	return (0);
}

// int	main(void)
// {
// 	t_game	game;
// 	t_param	param;

// 	param_init(&param);
// 	game.mlx_ptr = mlx_init();
// 	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "So Long and Thanks!");
// 	game.img_ptr = mlx_new_image(game.mlx_ptr, 1920, 1000);
// 	game.addr_ptr = mlx_get_data_addr(game.img_ptr, &game.bits_per_pixel, &game.line_length,
// 									&game.endian);
// 	put_pixel(game.img_ptr, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_ptr, 70, 70);
// 	mlx_hook(game.win_ptr, 3, 0, &goodbye, &param);
	

// 	mlx_loop(game.mlx_ptr);
// 	return (0);
// }