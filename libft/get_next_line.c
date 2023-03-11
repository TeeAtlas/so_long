/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:40:27 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/11 14:41:06 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int		i;
	int		read_count;
	char	c;
	char	*line;

	i = 0;
	read_count = 0;
	line = malloc(10000);
	while ((read_count = read(fd, &c, 1) > 0))
	{
		line[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!read_count && !line[i - 1]) || read_count == -1)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}