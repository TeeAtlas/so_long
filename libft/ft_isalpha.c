/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:33:01 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 17:42:20 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* all characters that are alpha return 1,
all that are not return 0*/

int	ft_isalpha(int c)
{	
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int	main(void)
{
	int temp; //must call a temp int for the value to be placed
	temp = ft_isalpha('a'); //executing fuction, int does not have to be called
	printf("%d\n", temp);
	return(0);
}*/
