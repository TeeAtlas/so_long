/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:04 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:29:33 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strchr, strrchr -- locate character in string
The strrchr() function is identical to strchr(),
except it locates the last occurrence of char.
int c - must be typecast into char because string 
is char not int*/

char	*ft_strrchr(const char *s, int c)
{
	int		s_i;
	int		c_i;

	s_i = 0;
	c_i = -1;
	while (s[s_i] != '\0')
	{
		if (s[s_i] == (char)c)
			c_i = s_i;
		s_i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[s_i]);
	if (c_i == -1)
		return (0);
	return ((char *)&s[c_i]);
}

/*int main (void) 
{
	// check(ft_strrchr(s, 't' + 256) == s); showLeaks();
	// char * empty = (char*)calloc(1, 1);
	char str[] = "tripouille";
	// char ch[] = "ltripouiel";;
    char *result;

    result = ft_strrchr(str, 't' + 256);
    printf("mine:%s\n", result);
	printf("theirs:%s\n", strrchr(str,'t' + 256));
    return(0);
}*/
