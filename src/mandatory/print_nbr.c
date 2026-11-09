/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:31:46 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/03 11:17:56 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_nbr(int n)
{
	char	*nbr;
	int		byte_p;

	nbr = ft_itoa(n);
	if (!nbr)
		return (-1);
	byte_p = ft_print_str(nbr);
	free(nbr);
	return (byte_p);
}

int	ft_print_unsigned(unsigned int n)
{
	int	value;
	int	count;

	value = 0;
	if (n > 9)
	{
		value = ft_print_unsigned(n / 10);
		if (value < 0)
			return (-1);
	}
	count = ft_print_char(n % 10 + '0');
	if (count < 0)
		return (-1);
	return (value + count);
}
