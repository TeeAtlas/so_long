/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:11:05 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:04:06 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memcpy() function copies n bytes from the object pointed to by src 
into the object pointed to by dst. If copying takes place between objects that 
overlap, the behavior is undefined. Returns original value of dst.
Param #1 destination
Param #2 source
Return value  void*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
	{
		*(ptr1++) = *(ptr2++);
	}
	return (dst);
}

/*int main(void)
{
 	char src[50] = "hello world";
 	char dst[50] = "goodbye world";
 	printf("%s\n", ft_memcpy(dst + 7, src + 3, 4));
 	return (0);
}*/
