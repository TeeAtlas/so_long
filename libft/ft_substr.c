/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:51:51 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:32:31 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		str = ft_calloc(1, sizeof(*s));
		if (!(str))
			return (NULL);
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = ft_calloc((len + 1), sizeof(*s));
	if (!(str))
		return (NULL);
	str = ft_memcpy(str, (s + start), len);
	return (str);
}

/*int	main(void)
{
 	char number[] = "pot belly pig";
 	printf("original:\n");
 	printf("%s\n", number);
 	printf("after my function:\n");
 	printf("%s\n", ft_substr(number, 2, 4));
 	return(0);
}*/
