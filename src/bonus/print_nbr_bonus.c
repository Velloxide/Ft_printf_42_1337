/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:58:11 by saboutay          #+#    #+#             */
/*   Updated: 2026/11/06 15:16:22 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static long	ft_signed(t_spec *s, long n, char **prefix)
{
	if (n < 0)
	{
		n = -n;
		*prefix = "-";
	}
	else if (s->plus)
		*prefix = "+";
	else if (s->space)
		*prefix = " ";
	return (n);
}

int	ft_print_d_i(t_spec *s, int n)
{
	char	*buf;
	char	*prefix;
	long	nbr;
	int		len;
	int		count;

	prefix = "";
	nbr = ft_signed(s, n, &prefix);
	buf = ft_utoa_base(nbr, "0123456789", 10);
	if (!buf)
		return (-1);
	len = ft_strlen(buf);
	if (s->prec == 0 && nbr == 0)
		len = 0;
	count = ft_print_number(s, prefix, buf, len);
	free(buf);
	return (count);
}

int	ft_print_u(t_spec *s, unsigned int n)
{
	char	*buf;
	int		len;
	int		count;

	buf = ft_utoa_base(n, "0123456789", 10);
	if (!buf)
		return (-1);
	len = ft_strlen(buf);
	if (s->prec == 0 && n == 0)
		len = 0;
	count = ft_print_number(s, "", buf, len);
	free(buf);
	return (count);
}
