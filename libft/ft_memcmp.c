/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:45:03 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:02:37 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memcmp() compares byte string of s1 to bytes of s2
 A pointer of type const void* can contain the address of a data 
 item of any type but will not be changed by program*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned const char		*str1;
	unsigned const char		*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*int main(void)
{
 	char str1[] = "Spot the dog";
 	char str2[] = "Spot the lazy dog";
 	printf("%d\n", ft_memcmp(str1, str2, 20));
 	return 0;
}*/
