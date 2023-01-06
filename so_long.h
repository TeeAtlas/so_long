/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:08:43 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/06 18:48:04 by taboterm         ###   ########.fr       */
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

typedef	struct	s_vars
{
	// char	*map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}		t_vars;



// void	ft_free(t_vars *vars);
// void	read_map(char **argv, t_solong *game);
// int		close_window(t_vars *vars);
// void	push_pix(t_vars *data, int x, int y, int colour);

#endif