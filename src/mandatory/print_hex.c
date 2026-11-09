/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:52:47 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/04 13:05:23 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_helper(unsigned long long n, char spec)
{
	char	*hex;
	int		value;
	int		count;

	if (spec == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	value = 0;
	if (n > 15)
	{
		value = ft_print_helper(n / 16, spec);
		if (value < 0)
			return (-1);
	}
	count = ft_print_char(hex[n % 16]);
	if (count < 0)
		return (-1);
	return (count + value);
}

int	ft_print_hex(unsigned int n, char spec)
{
	return (ft_print_helper(n, spec));
}

int	ft_print_ptr(void *ptr)
{
	int					count;
	int					value;
	unsigned long long	addrs;

	addrs = (unsigned long long)ptr;
	if (!ptr)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	if (count < 0)
		return (-1);
	value = ft_print_helper(addrs, 'x');
	if (value < 0)
		return (-1);
	return (value + count);
}
