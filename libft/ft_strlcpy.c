/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:55:43 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:22:15 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* In computer programming, the strlcpy function is 
intended to replace the function strcpy (which 
copies a string to a destination buffer) with 
a secure version that cannot overflow the 
destination buffer. */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < (dstsize) - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*int	main(void)
{
 	char src[50] = "KittiesAndCritters";
 	char dst[50];
 	printf("Test \n");
 	printf("before function: %s \n", src);
 	ft_strlcpy(dst, src, 5);
	printf("after mine: %s \n", dst);
 	strlcpy(dst, src, 5);
 	printf("after theirs: %s \n", dst);
 	return 0;
}*/