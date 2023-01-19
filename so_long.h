/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:08:43 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/19 16:37:18 by taboterm         ###   ########.fr       */
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

typedef struct s_img
{
	void			*img_ptr;
	struct s_img	*next;
}					t_img;

typedef struct s_img_lst
{
	t_img	*first;
}			t_img_lst;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_lst	*img_list;
}				t_mlx;

typedef struct s_map
{
	char	*map_file;
	int		map_width;
	int		map_height;
	char	**map_arr;
}			t_map;

typedef struct s_tile
{
	char	*tile_file;
	int		tile_width;
	int		tile_height;
}			t_tile;

typedef	struct	s_game
{
	t_mlx	mlx;
	t_map	map;
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