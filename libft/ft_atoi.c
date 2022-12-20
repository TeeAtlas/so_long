/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:28:53 by taboterm          #+#    #+#             */
/*   Updated: 2022/11/05 14:51:23 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The atoi() A to I function converts the initial portion of 
the string pointed to by str to int representation. Can hold positive
and negative variables*/

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	signed long long int	res;
	int						sign;
	int						i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

int main ()
{
    char str[]="-2142";

    int val = ft_atoi(str);
    printf("%d\n", val);
   return(0);
}