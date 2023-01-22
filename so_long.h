/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:27 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/22 22:10:20 by taboterm         ###   ########.fr       */
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

typedef struct s_img
{
    void    *mlx;
    char    *addr;
    char    *name;
    int     w;
    int     h;
    int     bpp;
    int     line_len;
}    t_img;


typedef struct s_tile
{
    char    type;
    int     w;
    int     h;;
    void    *fl;
    t_param pos;
    // coordiates for placing tiles
}    t_tile;

typedef struct s_panel
{
    int         w;
    int         h;
    t_param     pos;
}    t_panel;


typedef struct s_map
{
    char    *map_file;
    int     w;
    int     h;
    int     grid_x;
    int     grid_y;
    char    **map_copy;
    t_tile  **tile;
}    t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    int     w;
    int     h;
    int     bsize;
    t_map   map;
    t_panel panel;
    t_tile  tile;
}    t_game;




void    param_init(t_param *param);
int     close_window(int keycode, t_param *param);
void    read_map(t_game *game);
// void    add_images_floor(t_game *game);
void	load_images(t_game *game);
void	img_to_win(t_game *game, void *img);
void	image_fail(t_game *game);
//function to initialize game
void    initialize_game(t_game *game);
//Function checks whether an input file is valid.
int     filecheck(t_game *game);
void    image_fail(t_game *game);
//Function checks that map file dimensions are valid.
int     valid_dimensions(char *mapfile);
//Function checks for a ".ber" ending in the string.
int     ends_ber(char *str);
//Function frees a pointer returning a given value.
int     free_num(void *ptr, int num);
void    image_fail(t_game *game);

#endif 