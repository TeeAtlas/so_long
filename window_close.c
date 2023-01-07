/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:18:55 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/07 17:30:14 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef	struct	s_vars
{
	void 	*mlx_ptr;
	void	*win_ptr;

}				t_vars;

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
// int	goodbye(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
// 	exit(0);
// }

int	goodbye(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		printf("keycode: %d", keycode);
		printf("keycode equals: %d\n", param->x);
		printf("keycode equals: %d\n", param->y);
		exit(0);
	}
	return(0);
}

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	main(void)
{
	t_vars	vars;
	t_param	param;

	param_init(&param);
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 1920, 1080, "Hello, World");
	mlx_hook(vars.win_ptr, 3, 0, &goodbye, &param);
	mlx_loop(vars.mlx_ptr);
	return (0);
}