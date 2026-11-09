/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:50:05 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/05 18:29:35 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	ft_print_char(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	return (write(1, &a, 1));
}

int	ft_print_str(char *s, size_t size)
{
	int		byte_p;
	int		value;
	size_t	i;

	if (!s)
		s = "(null)";
	i = 0;
	byte_p = 0;
	while (i < size)
	{
		value = ft_print_char(s[i]);
		if (value < 0)
			return (-1);
		byte_p += value;
		i++;
	}
	return (byte_p);
}

int	ft_print_c(t_spec *s, int c)
{
	char	a;

	a = (char)c;
	return (ft_print_field(s, &a, 1));
}

int	ft_print_s(t_spec *s, char *str)
{
	size_t	size;

	if (!str)
	{
		str = "(null)";
		if (s->prec >= 0 && s->prec < 6)
			str = "";
	}
	size = ft_strlen(str);
	if (s->prec >= 0 && (size_t)s->prec < size)
		size = s->prec;
	return (ft_print_field(s, str, size));
}
