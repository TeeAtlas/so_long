/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:23 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/10 21:08:37 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	game->fd = open(game->map_wlonly, O_RDONLY);
	game->line = get_next_line(game->fd);
	while (game->line)
	{
		if (!game->line)
			return (0);
		if (game->line)
			game->str_line = ft_strjoin(game->str_line, game->line);
	}
	return (game->str_line);
	game->array = ft_split(game->str_line, '\n');
	printf("%s\n", game->array);
	return (game->array);
	close(game->fd);
}