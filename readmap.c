/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/07 19:32:52 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counts columns and rows ie: height(row) and width(col)
// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE

char	*mod_join(char *str_a, char *str_b)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (str_a == 0)
	{
		str_a = (char *)malloc(sizeof(char) * 1);
		str_a[0] = '\0';
	}
	if (!str_a || !str_b)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str_a) + ft_strlen(str_b) + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (str_a)
	{
		while (str_a[++i] != '\0')
		{
			if (str_a[i] == '\n')
				i++;
			res[i] = str_a[i];
		}
	}
		// while (str_a[++i] != '\0')
		// 	res[i] = str_a[i];
	while (str_b[j] != '\0')
	{
		if (str_b[j] == '\n')
			j++;
		res[i++] = str_b[j++];
	}
	// while (str_b[j] != '\0')
	// 	res[i++] = str_b[j++];
	res[i] = '\0';
	free(str_a);
	return (res);
}

void	read_map(t_game *game)
{
	char	*line;
	
	game->fd = open(game->map.map_file, O_RDONLY);
	line =  get_next_line(game->fd);
	printf("what is here:%s\n", line); 
	game->map.rows = 0;
	game->map.h = 0;
	if (!line)
	{
		ft_printf("Error: No file to read\n");
		exit (EXIT_FAILURE);
	}
	printf("2what is here:%s\n", line);
	game->map.str_line = mod_strdup(line);
	printf("3what is here:%s\n", game->map.str_line); 
	game->map.w = ft_strlen(line) - 1;
	printf("4what is here:%d\n", game->map.w); 
	while (line)
	{
		line = get_next_line(game->fd);
		game->map.h++;
		if (line)
		{
			game->map.str_line = mod_join(game->map.str_line, line);
		}
		free(line);
	}
	printf("5what is here:%d\n", game->map.h);
	printf("6what is here:%s\n", game->map.str_line); 
	close(game->fd);
}
