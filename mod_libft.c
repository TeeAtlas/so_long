/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:28:59 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/05 23:49:31 by taboterm         ###   ########.fr       */
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
	while (i < len - 1 && src && src != '\n')
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
// joins lines into siglen arrage from map

char	*mod_strjoin(char *str_a, char *str_b)
{
	char 	*new_str;
	int		i;
	int		j;

	new_str = NULL;
	if (str_a == NULL && str_b == NULL)
		return (NULL);
	else if (str_a == NULL)
		return (mod_strdup(str_b));
	else if (str_b == NULL)
		return (mod_strdup(str_a));
	i = ft_strlen(str_a);
	j = ft_strlen(str_b);
	new_str = malloc(i + j);
	if (!new_str)
		return (NULL);
	mod_strlcpy(new_str, str_a, i + 1);
	mod_strlcpy(new_str + i, str_b, j + 1);
	free (str_a);
	free (str_b);
	return (new_str);
}

