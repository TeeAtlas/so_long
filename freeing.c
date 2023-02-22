/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:34:16 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/22 01:53:33 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function frees a pointer returning a given value.
int	free_num(void *ptr, int num)
{
	free(ptr);
	return (num);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_game(t_game *game)
{
	free(game->map.line);
	free(game->map.str_line);
	free_split(game->map.array);
	free(game);
}