/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:09:46 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/06 12:27:31 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

int	ft_pad(int pad, char c)
{
	int	i;
	int	value;

	i = 0;
	while (i < pad)
	{
		value = ft_print_char(c);
		if (value < 0)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_pad_side(t_spec *s, int len, int side)
{
	if (s->minus != side)
		return (0);
	return (ft_pad(s->width - len, ' '));
}

int	ft_print_field(t_spec *s, char *str, int len)
{
	int	count;
	int	value;

	count = ft_pad_side(s, len, 0);
	if (count < 0)
		return (-1);
	value = ft_print_str(str, len);
	if (value < 0)
		return (-1);
	value += count;
	count = ft_pad_side(s, len, 1);
	if (count < 0)
		return (-1);
	return (count + value);
}

static int	ft_print_body(char *prefix, int zeros, char *digits, int len)
{
	int	count;
	int	value;

	count = ft_print_str(prefix, ft_strlen(prefix));
	if (count < 0)
		return (-1);
	value = ft_pad(zeros, '0');
	if (value < 0)
		return (-1);
	count += value;
	value = ft_print_str(digits, len);
	if (value < 0)
		return (-1);
	return (count + value);
}

int	ft_print_number(t_spec *s, char *prefix, char *digits, int len)
{
	int	plen;
	int	zeros;
	int	total;
	int	count;
	int	value;

	plen = ft_strlen(prefix);
	zeros = ft_zeros(s, plen, len);
	total = plen + zeros + len;
	count = ft_pad_side(s, total, 0);
	if (count < 0)
		return (-1);
	value = ft_print_body(prefix, zeros, digits, len);
	if (value < 0)
		return (-1);
	count += value;
	value = ft_pad_side(s, total, 1);
	if (value < 0)
		return (-1);
	return (count + value);
}
