/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:04 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/12 12:42:21 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnum_mod(long n, char *base, int base_len)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -(n);
	}
	if (n == 0)
	{
		return (write(1, "0", 1), i + 1);
	}
	if (n >= base_len)
	{
		i += ft_putnum_mod(n / base_len, base, base_len);
		i += write(1, &base[n % base_len], 1);
	}
	else if (n < base_len)
		i += write(1, &base[n], 1);
	return (i);
}
