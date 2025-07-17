/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:42:28 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:17 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_take_address(void *arg)
{
	int			count;
	uintptr_t	address; // specific data type for storing a pointer safely

	count = 0;
	if (!arg)
		return (write(1, "(nil)", 5)); // pointer is NULL
	address = (uintptr_t)arg; // to process we need an int data type, so we cast generic pointer to uintptr_t
	count += write(1, "0x", 2); // prefix for hexadecimal pointer representation
	count += ft_print_address(address); // printing through recursion and digit-by-digit output in lowercase
	return (count);
}
