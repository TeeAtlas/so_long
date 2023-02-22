/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:51:41 by taboterm          #+#    #+#             */
/*   Updated: 2023/02/22 18:36:15 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
Null if allocation fails
Param #1 n integer to be converted 
using long int to */

int	ft_length(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (i + 1);
	if (nb < 0)
	{
		nb *= (-1);
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_if(long nbr, char *nbr2)
{
	if (nbr == 0)
		nbr2[0] = 48;
	return (nbr2);
}

char	*ft_itoa(int n)
{
	char			*num;
	size_t			i;
	long int		nb;

	nb = n;
	i = ft_length(nb);
	num = (char *)malloc(sizeof(char) * (ft_length(nb) + 1));
	if (!num)
		return (NULL);
	num[i--] = '\0';
	ft_if(nb, num);
	if (nb < 0)
	{
		num[0] = '-';
		nb *= (-1);
	}
	while (nb > 0)
	{
		num[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (num);
}

// int	main(void)
// {
//  	printf("return is:\n%s\n",ft_itoa(-3456));
// 	return (0);
// }
