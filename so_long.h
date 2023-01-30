/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:27 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/30 21:30:45 by taboterm         ###   ########.fr       */
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
# include "images_events.h"

typedef struct s_param
{
    int     x;
    int     y;
}                t_param;

// typedef struct s_img
// {
//     void    *mlx;
//     char    *addr;
//     char    *name;
//     int     w;
//     int     h;
//     int     bpp;
//     int     line_len;
// }    t_img;


typedef struct s_tile
{
    int     w;
    int     h;;
	int		tile_dimension;
    void    *img;
    t_param pos;
    // coordiates for placing tiles
}    t_tile;

// typedef struct s_panel
// {
//     int         w;
//     int         h;
//     t_param     pos;
// }    t_panel;


typedef struct s_map
{
    char    *map_file;
    int     rows;
    int     w;
    int     h;
    char    *str;
    char    *str_2;
    char    **array;
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
int     close_window(int keycode, t_param *param);
void    reading_map(t_game *game);
void	read_map_array(t_game *game);
int	    display_map(t_game *game, char *mapfile);

// adding images
char	*display_tile(t_game *game);

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