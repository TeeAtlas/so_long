/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:55:42 by taboterm          #+#    #+#             */
/*   Updated: 2022/06/25 18:34:24 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{	
	if (c >= 97 && c <= 122)
	c -= 32;
	{
		return (c);
	}
}

/*int	main(void)
{
 	char ch;
 	ch = 'g';
 	printf("uppercase of %c is %c\n", ch, ft_toupper(ch));
 	printf("uppercase of %d is %d\n", ch, ft_toupper(ch));
 	return	0;
}*/