/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:32:10 by taboterm          #+#    #+#             */
/*   Updated: 2022/12/20 16:19:54 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_output(char *str_a)
{
	int		i;
	char	*s;

	i = 0;
	if (!str_a[i])
		return (NULL);
	while (str_a[i] != '\0' && str_a[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str_a[i] != '\0' && str_a[i] != '\n')
	{
		s[i] = str_a[i];
		i++;
	}
	if (str_a[i] == '\n')
	{
		s[i] = str_a[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*gnl_new_line(char *str_a)
{
	long int	i;
	long int	j;
	char		*str;

	i = 0;
	while (str_a[i] != '\0' && str_a[i] != '\n')
		i++;
	if (str_a[i] == '\0')
	{
		free(str_a);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(str_a) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str_a[i] != '\0')
		str[j++] = str_a[i++];
	str[j] = '\0';
	free (str_a);
	return (str);
}

char	*gnl_read_line(int fd, char *str_a)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(str_a, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str_a = ft_strjoin(str_a, buffer);
	}
	free(buffer);
	return (str_a);
}

char	*get_next_line(int fd)
{
	static char	*str_a;
	char		*str_b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_a = gnl_read_line(fd, str_a);
	if (!str_a)
	{
		free(str_a);
		return (NULL);
	}
	str_b = gnl_output(str_a);
	str_a = gnl_new_line(str_a);
	return (str_b);
}
