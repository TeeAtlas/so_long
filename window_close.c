/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:18:55 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/07 19:17:48 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef	struct	s_game
{
	void 	*mlx_ptr;
	void	*win_ptr;

}				t_game;

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

int	goodbye(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	printf("keycode =%d", keycode);
	return(0);
}

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	main(void)
{
	t_game	game;
	t_param	param;

	param_init(&param);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "Hello, World");
	mlx_hook(game.win_ptr, KEY_ESC, 0, &goodbye, &param);
	mlx_loop(game.mlx_ptr);
	return (0);
}