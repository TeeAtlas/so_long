/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:45:11 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 17:34:35 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* allocates the requested memory and returns a pointer to it. 
The difference in malloc and calloc is that malloc does not 
set the memory to zero where as calloc sets allocated memory 
to zero.*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

/* int	main(void)
{
 	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
 	printf("String after bytes %s\n", ft_calloc(SIZE_MAX, SIZE_MAX));
 	printf("String after theirs %s\n", calloc(SIZE_MAX, SIZE_MAX));
}*/
