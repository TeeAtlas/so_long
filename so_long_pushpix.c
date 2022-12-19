/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pushpix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:49:38 by taboterm          #+#    #+#             */
/*   Updated: 2022/12/19 15:56:31 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_opengl_20191021/mlx.h"

int	main(void)
{
	void	*img;
	void	*mlx;
	
	mlx =  mlx_init();
	img = mlx_new_window(mlx, 1920, 1080);
}