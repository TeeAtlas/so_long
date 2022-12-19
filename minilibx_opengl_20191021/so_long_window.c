/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:57:09 by taboterm          #+#    #+#             */
/*   Updated: 2022/12/19 13:27:08minilibx_opengl_20191021 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_opengl_20191021/mlx.h"
// create variables to execute mlx_init function
// to establish connection and to call new window function
// then initiate window rendering
// will return a void pointer that holds current mlx instance

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello, World!");
			
	mlx_loop(mlx);
}