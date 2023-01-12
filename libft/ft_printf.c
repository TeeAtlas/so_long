/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:42:26 by taboterm          #+#    #+#             */
/*   Updated: 2023/01/12 12:41:49 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversion(va_list args, const char flag)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (flag == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (flag == 'u')
		len += ft_uitoa(va_arg(args, unsigned int));
	else if (flag == 'i' || flag == 'd')
		len += ft_putnum_mod(va_arg(args, int), "0123456789", 10);
	else if (flag == 'x')
		len += ft_putnum_mod
			(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (flag == 'X')
		len += ft_putnum_mod
			(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (flag == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (flag == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, fmt);
	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			len += ft_conversion(args, fmt[i]);
		}
		else
			len += ft_printchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}
