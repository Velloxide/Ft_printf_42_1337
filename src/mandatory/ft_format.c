/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:27:14 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/02 19:09:55 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_undefined(char spec)
{
	int	value;
	int	count;

	if (spec == '\0')
		return (-1);
	count = ft_print_char('%');
	if (count < 0)
		return (-1);
	value = ft_print_char(spec);
	if (value < 0)
		return (-1);
	return (count + value);
}

int	ft_format(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (spec == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (spec == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (spec == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), spec));
	else if (spec == '%')
		return (ft_print_char('%'));
	return (ft_undefined(spec));
}
