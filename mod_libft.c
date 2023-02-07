/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:28:59 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/07 17:30:57 by taboterm         ###   ########.fr       */
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

char	*mod_strjoin(char *str_a, char *str_b)
{
	char 	*new_str;
	size_t	ct_str_a;
	size_t	ct_str_b;

	new_str = NULL;
	if (str_a == NULL && str_b == NULL)
		NULL;
	else if (str_a == NULL)
		return (mod_strdup(str_b));
	else if (str_b == NULL)
		return (mod_strdup(str_a));
	ct_str_a = maplinelen(str_a);
	ct_str_b = maplinelen(str_b);
	new_str = malloc(ct_str_a + ct_str_b);
	if (!new_str)
		return (NULL);
	mod_strlcpy(new_str, str_a, ct_str_a + 1);
	mod_strlcpy(new_str + ct_str_a, str_b, ct_str_b + 1);
	free (str_a);
	free (str_b);
	return (new_str);
}

