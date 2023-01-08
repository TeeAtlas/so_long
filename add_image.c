/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:20:18 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/08 15:10:26 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
#include "./minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;	
	void	*img;
	int		img_width;
	int		img_height;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "tile_test");
	img = mlx_xpm_file_to_image(mlx_ptr, "./images/floor.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_loop(mlx_ptr);
	return(0);
}