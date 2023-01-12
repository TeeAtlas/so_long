/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:52:40 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/12 12:42:30 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (i + 1);
	if (n < 0)
	{
		n *= (-1);
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_uitoa(unsigned long int n)
{
	unsigned long int		len;
	char					*nbr;

	len = ft_len(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	if (n == 0)
		len = write(1, "0", 1);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}	
	while (*(nbr + len))
	{
		write(1, (nbr + len), 1);
		len++;
	}
	free(nbr);
	return (len);
}
