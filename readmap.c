/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/22 12:02:06 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts columns and rows ie: height(row) and width(col)
// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE

void	printsplit(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			ft_printf("%c", split[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

// void	walled_t_b(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = game->map.h - 1;
// 	while (game->map.array[i])
// 	{
// 		while (i < game->map.w)
// 		{
// 			if (game->map.array[0][i] != '1')
// 				ft_printf("Error: Not walled in!\n");
// 			if (game->map.array[j][i] != '1')
// 				ft_printf("Error: Not walled in!\n");
// 			i++;
// 		}
// 	}
// 	exit (EXIT_FAILURE);
// }

void	minmap(t_game *game)
{
	int	i;
	int	j;
	int	wallcount;
	int	floorcount;
	int	collcount;
	int	playerct;
	int	exitcount;
	
	wallcount = 0;
	floorcount = 0;
	collcount = 0;
	playerct = 0;
	exitcount = 0;
	i = 0;
	j = 0;
	while (i < game->map.h - 1)
	{
		j = 0;
		while (j < game->map.w - 1)
		{
			if (game->map.array[i][j] == '1')
				wallcount++;
			if (game->map.array[i][j] == '0')
				floorcount++;
			if (game->map.array[i][j] == 'C')
				collcount++;
			if (game->map.array[i][j] == 'P')
				playerct++;
			if (game->map.array[i][j] == 'E')
				exitcount++;
			j++;
		}
		i++;
	}
	if (collcount < 1 || exitcount != 1 || playerct != 1)
	{
		// ft_printf("Coll: %i, Exit: %i, Play: %i\n", collcount, exitcount, playerct);
		ft_printf("Error: Wrong number of map elements!\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	notwalledinexit(t_game *game)
{
	ft_printf("Error: Not walled in!\n");
	free_game(game);
	exit(EXIT_FAILURE);
}

void	walled_sides(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < game->map.h - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		i++;
	}
	i = 0;
	j = game->map.w - 1;
	while (i < game->map.h - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		i++;
	}
}

void	walled_topbottom(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < game->map.w - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		j++;
	}
	j = 0;
	i = game->map.h - 1;
	while (j < game->map.w - 1)
	{
		if (game->map.array[i][j] != '1')
			notwalledinexit(game);
		j++;
	}
}

void	find_player(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (game->map.array[j])
	{
		while (game->map.array[j][i])
		{
			if (game->map.array[j][i] == 'P')
			{				
				game->pl_x = i;
				game->pl_y = j;
			}			
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

void	read_map(t_game *game)
{
	char	*temp;

	game->map.h = 0;
	game->map.rows = 0;
	game->fd = open(game->map.map_file, O_RDONLY);
	game->map.line =  get_next_line(game->fd);
	if (!game->map.line)
	{
		ft_printf("Error: No file to read\n");
		free_game(game);
		exit (EXIT_FAILURE);
	}
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
