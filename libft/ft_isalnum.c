/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:14:53 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 17:35:17 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
 	int temp; //must call a temp int for the value to be placed
 	temp = ft_isalnum('9'); //executing fuction, int does not have to be called
 	printf("%d\n", temp);
	return(0);
}*/