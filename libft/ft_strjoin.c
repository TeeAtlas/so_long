 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:22:39 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:19:54 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.


char	*ft_strjoin(char *str_a, char *str_b)
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
		while (str_a[++i] != '\0')
			res[i] = str_a[i];
	while (str_b[j] != '\0')
		res[i++] = str_b[j++];
	res[i] = '\0';
	free(str_a);
	return (res);
}