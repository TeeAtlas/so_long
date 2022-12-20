/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:47:16 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:28:41 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*strstr, strcasestr, strnstr -- locate a substring in a string
The strnstr() function locates the first occurrence of the null-terminated
string needle in the string haystack, where not more than len characters
are searched.  Characters that appear after a `\0' character are not
searched. Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*l;

	l = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (len--)
	{
		if (*l == *haystack)
			l++;
		else
		{
			haystack -= (l - needle);
			len += (l - needle);
			l = needle;
		}
		haystack++;
		if (*l == '\0')
			return ((char *)(haystack - (l - needle)));
		if (*haystack == '\0')
			break ;
	}
	return (NULL);
}

/*int main(void) 
{
 	char haystack[30] = "aaabcabcd";
 	char needle[10] = "aabc";
 	char * empty = (char*)"";
    printf("The substring is: %s\n", ft_strnstr(haystack, "a", 1));
 	printf("The o is: %s\n", strnstr(haystack, "a", 1));
    return(0);
}*/
