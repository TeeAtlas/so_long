/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:35:10 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/07 17:44:57 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
#include "./minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_game
{
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
}		t_game;

void	put_pixel(t_game *game, int x, int y, int colour)
{
	char	*dst;

	dst = game->addr_ptr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}