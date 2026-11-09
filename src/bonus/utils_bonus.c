/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:43:26 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/07 14:28:12 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static int	ft_undefined(t_spec *spec)
{
	int	value;
	int	count;

	if (spec->type == '\0')
		return (-1);
	value = ft_print_char('%');
	if (value < 0)
		return (-1);
	count = ft_print_char(spec->type);
	if (count < 0)
		return (-1);
	return (value + count);
}

static int	ft_format(t_spec *spec, va_list *args)
{
	if (spec->type == 'c')
		return (ft_print_c(spec, va_arg(*args, int)));
	else if (spec->type == 's')
		return (ft_print_s(spec, va_arg(*args, char *)));
	else if (spec->type == 'p')
		return (ft_print_p(spec, va_arg(*args, void *)));
	else if (spec->type == 'd' || spec->type == 'i')
		return (ft_print_d_i(spec, va_arg(*args, int)));
	else if (spec->type == 'u')
		return (ft_print_u(spec, va_arg(*args, unsigned int)));
	else if (spec->type == 'x' || spec->type == 'X')
		return (ft_print_x(spec, va_arg(*args, unsigned int)));
	else if (spec->type == '%')
		return (ft_print_char('%'));
	return (ft_undefined(spec));
}

char	*ft_utoa_base(unsigned long long n, char *bufbase, int base)
{
	unsigned long long	nbr;
	int					len;
	char				*ptr;

	len = (n == 0);
	nbr = n;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (len > 0)
	{
		ptr[--len] = bufbase[n % base];
		n /= base;
	}
	return (ptr);
}

int	ft_zeros(t_spec *s, int plen, int len)
{
	int	zeros;

	zeros = 0;
	if (s->prec > len)
		zeros = s->prec - len;
	if (s->zero && !s->minus && s->prec < 0 && s->width > plen + len)
		zeros = s->width - plen - len;
	return (zeros);
}

int	ft_handle(const char *format, int *i, va_list *args)
{
	t_spec	spec;
	int		value;

	value = ft_parse(format + (*i + 1), &spec);
	if (value < 0)
		return (-1);
	*i += value;
	return (ft_format(&spec, args));
}
