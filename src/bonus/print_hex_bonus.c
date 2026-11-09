/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:57:13 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/07 14:52:34 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static char	*ft_get_prefix(t_spec *s)
{
	char	*prefix;

	if (s->plus)
		prefix = "+0x";
	else if (s->space)
		prefix = " 0x";
	else
		prefix = "0x";
	return (prefix);
}

int	ft_print_p(t_spec *s, void *ptr)
{
	unsigned long long	addrs;
	char				*buf;
	int					count;
	int					len;

	if (!ptr)
		return (ft_print_field(s, "(nil)", 5));
	addrs = (unsigned long long)ptr;
	buf = ft_utoa_base(addrs, "0123456789abcdef", 16);
	if (!buf)
		return (-1);
	len = ft_strlen(buf);
	count = ft_print_number(s, ft_get_prefix(s), buf, len);
	free(buf);
	return (count);
}

int	ft_print_x(t_spec *s, unsigned int n)
{
	char	*buf;
	char	*base;
	char	*prefix;
	int		len;
	int		count;

	prefix = "0X";
	if (s->type == 'x')
	{
		base = "0123456789abcdef";
		prefix = "0x";
	}
	else
		base = "0123456789ABCDEF";
	if (!s->hash || n == 0)
		prefix = "";
	buf = ft_utoa_base(n, base, 16);
	if (!buf)
		return (-1);
	len = ft_strlen(buf);
	if (s->prec == 0 && n == 0)
		len = 0;
	count = ft_print_number(s, prefix, buf, len);
	free(buf);
	return (count);
}
