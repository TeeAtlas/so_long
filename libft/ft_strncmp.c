/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:22:40 by taboterm          #+#    #+#             */
/*   Updated: 2022/12/21 09:34:04 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* strcmp, strncmp -- compare strings not binary data
 characters that appear after '\0' are not compared
Param #1 pointer to original
Param #2 pointer to string to be compared
Param #3 the caparison is done using unsigned char
'\200' is greater than '\0'
Return int value*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// int main (void) 
// {
// 	char str1[] = "Hello\200";
// 	char str2[] = "Hello\0";
// 	int n;
// 	n = 89;
 
// 	ft_strncmp(str1, str2, n);
// 	printf("return value is:%d\n", ft_strncmp(str1, str2, n));
// 	printf("original value is:%d\n", strncmp(str1, str2, n));

//  	return(0);
// }