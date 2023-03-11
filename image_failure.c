/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_failure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:09:11 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/11 12:24:40 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	image_fail(t_game *game)
{
	ft_printf("Error: Failed to load image\n");
	free(game);
	exit(EXIT_FAILURE);
}
