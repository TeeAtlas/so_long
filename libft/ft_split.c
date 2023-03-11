/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:44:32 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/01 20:21:25 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* write a function that takes a string, splits it into words
and returns them as a NULL-terminated array of strings. A "word" is definded as
as part of a string delimited either by spaces/tabs/new lines, or by 
the start/end of the string. */

int	num_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}	
		}
		else
		{
			i++;
		}
	}
	return (words);
}

char	*ft_word(const char *s1, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		word[i] = s1[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((num_words(s, c) + 1) * sizeof(char *));
	if (!tab || !s)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			tab[j++] = ft_word(s, index, i);
			index = -1;
		}
	}
	tab[j] = 0;
	return (tab);
}

// int		main(void)
// {
//  	char	**tab;
//  	unsigned int	i;
//  	int	c;
	
//  	c = 0;
//  	tab = ft_split("Tania     says   hi, and hello !   ", 040);
//  	i = 0;
//  	while (i < 7)
//  	{
//  		printf("tab[%d] = %s\n", i, tab[i]);
//  		i++;
//  	}
//  	return(0);
// }
