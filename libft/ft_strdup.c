/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:26:36 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:15:40 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strdup() function allocates sufficient memory
for a copy of the string s1, does the copy, and returns 
pointer to it.  The pointer may subsequently be used as an
argument to the function free(3).
Param #1 pointer to string1*/

char	*ft_strdup(const char *s1)
{
	char		*s2;
	int			i;
	int			size;

	i = 0;
	size = 0;
	s2 = (char *)malloc (sizeof(char) * ft_strlen(s1) + 1);
	while (s1[size])
		++size;
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*int main(void)
{
     char str1[] = "I'm a copy";
     char *p;

     p = ft_strdup(str1);
     printf("\nthis string is: %s\n",ft_strdup(str1));
     printf("and this string points to: %s\n", p);
}*/