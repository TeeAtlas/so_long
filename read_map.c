/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/24 13:26:00 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts columns and rows ie: height(row) and width(col)
// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE

// void	printsplit(char **split)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (split[i])
// 	{
// 		j = 0;
// 		while (split[i][j])
// 		{
// 			ft_printf("%c", split[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

void	find_player(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	game->coll_count = 0;
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == 'P')
			{				
				game->pl_x = i;
				game->pl_y = j;
			}			
			if (game->map.array[j][i] == 'C')
				game->coll_count++;
			i++;
		}
		i = 0;
		j++;
	}			
}

// void	read_map(t_game *game)
// {
// 	game->fd = open(game->map.map_file, O_RDONLY);
// 	game->map.line =  get_next_line(game->fd);
// 	game->map.rows = 0;
// 	game->map.h = 0;
// 	if (!game->map.line)
// 	{
// 		ft_printf("Error: No file to read\n");
// 		exit (EXIT_FAILURE);
// 	}
// 	game->map.str_line = ft_strdup(game->map.line);
// 	game->map.w = maplinelen(game->map.line);
// 	while (game->map.line)
// 	{
// 		game->map.h++;
// 		free(game->map.line);
// 		game->map.line = get_next_line(game->fd);
// 		if (game->map.line)
// 		{
// 			game->map.str_line = ft_strjoin(game->map.str_line, game->map.line);
// 		}
// 		free(game->map.line);
// 	}
// 	game->map.array = ft_split(game->map.str_line, '\n');
// 	close(game->fd);
// }

void	no_file(t_game *game)
{
	ft_printf("Error: No file to read\n");
	free_game(game);
	exit (EXIT_FAILURE);
}

void	read_map(t_game *game)
{
	char	*temp;

	game->map.h = 0;
	game->map.rows = 0;
	game->fd = open(game->map.map_file, O_RDONLY);
	game->map.line =  get_next_line(game->fd);
	if (!game->map.line)
		no_file(game);
	game->map.w = maplinelen(game->map.line);
	game->map.str_line = ft_strdup(game->map.line);
	while (game->map.line)
	{
		game->map.h++;
		if (game->map.h > 1)
		{
			temp = ft_strjoin(game->map.str_line, game->map.line);
			free(game->map.str_line);
			game->map.str_line = temp;
		}
		free(game->map.line);
		game->map.line = get_next_line(game->fd);
	}
	game->map.array = ft_split(game->map.str_line, '\n');
	close(game->fd);
}
