/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:00:32 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 17:53:01 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*  The ft_memchr() function locates the first occurrence 
of c (converted to an unsigned char) in string s. Returns a
pointer to the byte located, or NULL if no such byte exists 
within n bytes*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (*str == ch)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
 	char	str[] = "1234567c89";
 	const	char	*c1;
 	printf("Test \n");
 	printf("before function: %s\n", str);
 	printf("after function: %s\n", ft_memchr(str, 'c', 10));
 	return	0;
}*/