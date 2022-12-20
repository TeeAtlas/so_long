/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:29:09 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 17:43:48 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int main(void)
{
 	int temp; //must call a temp int for the value to be placed
 	temp = ft_isascii('1'); //executing fuction, int does not have to be called
 	printf("%d\n", temp);
 	return(0);
}*/