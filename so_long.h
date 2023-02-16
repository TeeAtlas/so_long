/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:27 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/16 20:29:51 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define TILE		100
# define FLOOR		"./images/floor.xpm"
# define EXIT		"./images/exit.xpm"
# define PLAY		"./images/play.xpm"
# define WALL		"./images/wall.xpm"
# define COLL		"./images/collect.xpm"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_param
{
	int		x;
	int		y;
} 		t_param;

typedef struct s_tile
{
	// void	*img;
	void	*fl;
	void	*wl;
	void	*pl;
	void	*ex;
	void	*cl;
	int		w;
	int		h;
	int		tile_dimension;
}		t_tile;

typedef struct s_map
{
	char	*map_file;
	char	*line;
	int		rows;
	int		w;
	int		h;
	char	*str;
	char	*str_line;
	char	**array;
	char	**map_copy;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		fd;
	int		x;
	int		y;
	int		bsize;
	t_map	map;
	t_tile	tile;
}		t_game;




// void	param_init(t_param *param);
int		close_window(int keycode);

// static void	read_map_line(t_game *game);
void	read_map(t_game *game);

// adding images
void	xpm_to_pixel(t_game *game);
void	load_image(t_game *game);

//function to initialize game
void	initialize_game(t_game *game);

//Function checks whether an input file is valid.
int		filecheck(t_game *game);
void	image_fail(t_game *game);

//Function checks that map file dimensions are valid.
int		valid_dimensions(char *mapfile);

//strlen for maps
int		maplinelen(char *mapline);

//Function checks for a ".ber" ending in the string.
int		ends_ber(char *str);

//Function frees a pointer returning a given value.
int		free_num(void *ptr, int num);
// void    image_fail(t_game *game);

void	player_up(t_game *game);
void	player_down(t_game *game);
void	player_left(t_game *game);
void	player_right(t_game *game);
int		player_moves(int keycode, t_game *game);
#endif 