/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:08:43 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/07 17:44:41 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_game
{
	// char	*map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_game;

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

int		goodbye(int keycode, t_param *param);
void	param_init(t_param *param);
void	put_pixel(t_game *game, int x, int y, int colour);

#endif