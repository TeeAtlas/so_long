/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:08:43 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/11 01:35:22 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef	struct	s_game
{
	char	*map_file;  // 2d map
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
//	char	*map_wlonly;
	char	*addr_ptr;
	char	*str_line;
	char	*line;
	char	**array;
	int		col;
	int		row;
//	int		bits_per_pixel;
//	int		line_length;
	int		img_width;
	int		img_height;
//	int		endian;
	void	*floor;
	void	*img_ptr;
}			t_game;

typedef struct s_param
{
	int		x;
	int		y;
}				t_param;



void	param_init(t_param *param);
int		goodbye(int keycode, t_param *param);
void	put_pixel(t_game *game, int x, int y, int colour);
void	read_map(t_game *game);
// void	add_images_floor(t_game *game);

//Function checks whether an input file is valid.
int	filecheck(t_game *game);
//Function checks that map file dimensions are valid.
int	valid_dimensions(char *mapfile);
//Function checks for a ".ber" ending in the string.
int	ends_ber(char *str);
//Function frees a pointer returning a given value.
int	free_num(void *ptr, int num);

#endif