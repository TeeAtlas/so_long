/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:56:22 by taboterm          #+#    #+#             */
/*   Updated: 2022/08/15 12:25:45 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Outputs the char c to the file descriptor fd.
Param. #1 The character to output.
Param. #2 The file descriptor.
Return value None.
Libc functions write(2)*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
//     char letter = 'j';
//     ft_putchar_fd(letter, 2);
//     return(0);
// }
