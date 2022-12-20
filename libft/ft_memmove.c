/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:45:10 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:06:14 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* The memmove() function copies len bytes from string 
src to string dst.  The two strings may overlap; the 
copy is always done in a non-destructive manner. 
RETURN VALUES The memmove() function returns the original 
value of dst.*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*int	main(void)
{
 	char hel[50] = "hello world";
 	char bye[50] = "goodbye world";
 	ft_memmove(hel + 4, bye + 4, 6);
 	printf("before memmove; %s \n", hel);
 	printf("after memmove; %s \n", bye);
 	return	(0);
}*/