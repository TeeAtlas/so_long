/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:35:27 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/11 01:34:24 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function checks for a ".ber" ending in the string.
int	ends_ber(char *str)
{
	char	*ending;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			ending = ft_substr(str, i + 1, 4);
			break ;
		}
		i++;
	}
	if (ft_strncmp(ending, "ber", 4) == 0)
		return (1);
	return (0);
}

//Function checks whether character is valid map character.
int	is_valid_map(char ch)
{
	if (ch == '1' || ch == '0' || ch == 'C' || ch == 'E' || ch == 'P')
		return (1);
	return (0);
}

//Function counts the valid characters in a map line.
int	maplinelen(char *mapline)
{
	int	i;
	int	ct;

	ct = 0;
	i = 0;
	while (mapline[i] != '\0')
	{
		if (is_valid_map(mapline[i]) == 1)
			ct += 1;
		else if (mapline[i] == '\n')
			ct += 0;
		else
			return (-1);
		i++;
	}
	return (ct);
}

//Function checks that map file dimensions are valid.
int	valid_dimensions(char *mapfile)
{
	int		fd;
	int		length;
	int		currlen;
	char	*current;

	fd = open(mapfile, O_RDONLY);
	current = get_next_line(fd);
	length = maplinelen(current);
	if (length == -1)
		return (10);
	while (current != NULL)
	{
		free(current);
		current = get_next_line(fd);
		if (current == NULL)
			break ;
		currlen = maplinelen(current);
		if (currlen == -1)
			return (free_num(current, 10));
		if (currlen != length)
			return (free_num(current, 0));
	}
	return (1);
}

//Function checks whether an input file is valid.
int	filecheck(t_game *game)
{
	if (ends_ber(game->map_file) == 0)
	{
		ft_putstr_fd("Error: Filename\n", 2);
		return (0);
	}
	if (valid_dimensions(game->map_file) == 0)
	{
		ft_putstr_fd("Error: Invalid map dimensions\n", 2);
		return (0);
	}
	else if (valid_dimensions(game->map_file) == 10)
	{
		ft_putstr_fd("Error: Invalid map character\n", 2);
		return (0);
	}
	return (1);
}

// Testity test test
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("In:%s, ends_ber:%d\n", argv[1], ends_ber(argv[1]));
	printf("valid_dimensions:%d\n", valid_dimensions(argv[1]));
	return (0);
}
//*/