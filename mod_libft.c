/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:28:59 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/07 20:48:46 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// modified libft functions excluding new line
// saves first new line, no overhang
// modified strdup

char	*mod_strdup(char *str)
{
	char	*new_str;
	int		i;
	int		ct;
	
	new_str = NULL;
	i = 0;
	ct = maplinelen(str);
	new_str = malloc (sizeof(char) * maplinelen(str) + 1);
	if (!new_str)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

//modified ft_strlcpy without '\n'
//copies src to dst till '\n' reached

int	mod_strlcpy(char *dst, char *src, int len)
{
	int src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
		return (src_len);
	while (i < len - 1 && *src && *src != '\n')
	{
		dst[i] = src[i];
		dst++;
		src++;
		i++; 
	}
	dst[i] = '\0';
	return (src_len);
}

// modified strjoin without newline
// joins lines into sig line arraged from map

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
	while (str_b[j] != '\0')
	{
		if (str_b[j] == '\n')
			j++;
		res[i++] = str_b[j++];
	}
	res[i] = '\0';
	free(str_a);
	return (res);
}

