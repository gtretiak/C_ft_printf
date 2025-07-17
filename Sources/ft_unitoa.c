/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:58 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 18:08:12 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_countn(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i); // returns the number of digits in nb
}

char	*ft_unitoa(unsigned int n)
{
	short	l;
	char	*s;

	l = ft_countn(n);
	s = malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n == 0) // edge case
	{
		s[0] = '0';
		return (s);
	}
	while (n) // starting from the last char in the string to return (except the null-terminator)
	{ // we put into it the last digit, converted to a character
		s[--l] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
