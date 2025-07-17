/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:40:29 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 15:51:37 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args; // to handle variable arguments
	int		count; // track th total number of characters printed

	va_start(args, format); // initializing va_list to begin retrieving the variable arguments from format
	count = 0;
	if (!format) // if nothing has passed to the function
		return (write (1, "(null)", 6));
	while (*format)
	{
		if (*format == '%') // once we found % sign...
			count += ft_check_chars(*(++format), args); // ... we check the following char
		else // otherwise just printing as is
		{
			ft_putchar_fd(*(char *)format, 1);
			count++;
		}
		format++;
	}
	va_end(args); // cleaning up for va_list
	return (count);
}
