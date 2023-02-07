/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:27 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/07 17:53:46 by taboterm         ###   ########.fr       */
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

# define TILE       100
# define FLOOR		"images/floor_100x100.xpm"
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_param
{
    int     x;
    int     y;
}                t_param;

typedef struct s_tile
{
    void    *img;
    void    *fl;
    int     w;
    int     h;;
	int		tile_dimension;
}    t_tile;

typedef struct s_map
{
    char    *map_file;
    char    *line;
    int     rows;
    int     w;
    int     h;
    char    *str;
    char    *str_line;
    char    *array;
    char    **map_copy;
    t_tile  **tile;
}    t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    int     fd;
    int     w;
    int     h;
    int     bsize;
    t_map   map;
    t_tile  tile;
}    t_game;




void    param_init(t_param *param);
int     close_window(int keycode);
void    read_map(t_game *game);
char	*mod_strdup(char *str);
char	*mod_strjoin(char *str_a, char *str_b);
int	    mod_strlcpy(char *dst, char *src, int len);


// adding images
void	image_xpm_to_map(t_game *game);

//function to initialize game
void    initialize_game(t_game *game);

//Function checks whether an input file is valid.
int     filecheck(t_game *game);
void    image_fail(t_game *game);

//Function checks that map file dimensions are valid.
int     valid_dimensions(char *mapfile);

//strlen for maps
int     maplinelen(char *mapline);

//Function checks for a ".ber" ending in the string.
int     ends_ber(char *str);

//Function frees a pointer returning a given value.
int     free_num(void *ptr, int num);
void    image_fail(t_game *game);

//function  mallocs memory for map and map copy
void	malloc_maps(t_game *game);

#endif 