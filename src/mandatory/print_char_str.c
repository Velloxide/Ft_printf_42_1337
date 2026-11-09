/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:54:39 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/03 19:57:51 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	return (write(1, &a, 1));
}

int	ft_print_str(char *s)
{
	int	byte_p;
	int	value;

	if (!s)
		s = "(null)";
	byte_p = 0;
	while (*s)
	{
		value = ft_print_char(*s);
		if (value < 0)
			return (-1);
		byte_p += value;
		s++;
	}
	return (byte_p);
}
