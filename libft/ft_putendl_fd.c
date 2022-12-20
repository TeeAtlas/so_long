/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:02:09 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:10:27 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Outputs the string s to the file desciptor fd followed by a '\n'.
Param. #1 The string to output.
Param. #2 The file descriptor.
Return value - none.
Libc functions write(2).*/

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*int	main(void)
{
	char str[] = "lorem ipsum dolor sit amet";
 	ft_putendl_fd(str, 2);
 	return(0);
}*/