/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:14:17 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/04 15:43:47 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_abort(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		value;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			value = ft_handle(format, &i, &args);
		else
			value = ft_print_char(format[i]);
		if (value < 0)
			return (ft_abort(&args));
		count += value;
		i++;
	}
	va_end(args);
	return (count);
}
