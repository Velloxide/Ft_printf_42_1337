/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:38:29 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/22 10:15:41 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(int digit, unsigned long long nbr, int sign, int *over)
{
	unsigned long long	limit;
	unsigned long long	long_max_value;

	long_max_value = (((unsigned long long)-1) / 2);
	limit = long_max_value + (sign < 0);
	if (nbr > (limit - digit) / 10)
	{
		*over = (int)(limit * sign);
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long long	nbr;
	int					sign;
	int					over;

	while (*nptr && (*nptr == 32 || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	nbr = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (ft_overflow((*nptr - 48), nbr, sign, &over))
			return (over);
		nbr = (nbr * 10) + (*nptr - 48);
		nptr++;
	}
	return ((int)(nbr * sign));
}
