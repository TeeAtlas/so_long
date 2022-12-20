/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:32 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:07:44 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* The memset() function writes len bytes of value c 
(converted to an unsigned char) to the string b.*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)b;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (b);
}

/*int main(void)
{
 	char	string[10] = "bing bong";
 	printf("String before memset(); %s \n", string);
 	ft_memset(string, '*', 4 * sizeof(string[0])); //sets first characters to *
 	printf("String after memset(): %s \n", string);
 	memset(string, '*', 4 * sizeof(string[0])); 
 	printf("String after original(): %s \n", string);
 	return	(0);
}*/