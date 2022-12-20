/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:31:08 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:20:46 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* The strlcat() function achieves the same goal as the 
strcat() function: to append one string onto the end of the 
other. The problem with strcat(), however, is that a size limitation 
isn’t set for the destination buffer. It’s quite possible for this 
buffer to overflow.As a solution, the strlcat() function offers an 
additional argument, dstsize. This argument sets the length of the 
destination string, effectively equal to its buffer size.*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen (dst);
	srclen = ft_strlen (src);
	i = 0;
	if (dstsize < (dstlen + 1))
	{
		return (dstsize + srclen);
	}
	if (dstsize > (dstlen + 1))
	{
		while (src[i] != '\0' && (dstlen + 1 + i) < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

/*int	main(void)
{
 	char src[] = "Life is like";
 	char dst[] = "a box of chocolates";
 	int p;
 	size_t len;

 	len = 45;
 	p = ft_strlcat(dst, src, len);
 	printf("test \n");
 	printf("before function: %s \n", src);
 	printf("return value:%zu\n", len);
 	printf("return value after:%d\n", p);
 	printf("original:%lu\n:",strlcat(dst, src, len));
}*/