/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:42:48 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/12 12:42:10 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_pt_len(unsigned long int addi)
{
	int	length;

	length = 0;
	while (addi != 0)
	{
		length++;
		addi = addi / 16;
	}
	return (length);
}

void	ft_pointer(unsigned long int num)
{
	if (num >= 16)
	{
		ft_pointer(num / 16);
		ft_pointer(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
		}
		else
		{
			ft_putchar_fd((num - 10 + 'a'), 1);
		}
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
	{
		len += write(1, "0", 1);
	}
	else
	{
		ft_pointer(ptr);
		len += ft_pt_len(ptr);
	}
	return (len);
}
