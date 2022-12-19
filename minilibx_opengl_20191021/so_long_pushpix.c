/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pushpix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:49:38 by taboterm          #+#    #+#             */
/*   Updated: 2022/12/19 16:51:06 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_opengl_20191021/mlx.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data

int	main(void)
{
	void	*img;
	void	*mlx;
	
	mlx =  mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	/* after creating an image, we can call 'mlx_get_data_addr'. we pass
	/* bits_per_pixel', 'line_length'. and 'endian' by regerence. These will
	/* then be set accordingly for the *current* data address*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}


