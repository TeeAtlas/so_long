/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:41:47 by taboterm          #+#    #+#             */
/*   Updated: 2022/07/11 17:09:34 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Outputs the string s to the file descriptor fd.
Param. #1 The string to output.
Param. #2 The file descriptor. Return value None. 
Libc functions write(2).*/

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != 0)
	{
		write (fd, &s[i], 1);
		i++;
	}
}

/*int main(void) 
{
	char letter[] = "Stay gold, Pony Boy.\n";
 	ft_putstr_fd(letter, 1);
 	return(0);
}*/
