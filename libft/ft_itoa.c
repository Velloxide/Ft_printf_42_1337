/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:45:02 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/18 23:23:38 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nb;
	int		len;

	nb = n;
	len = (n <= 0);
	while (n && ++len)
		n /= 10;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		ptr[0] = '-';
	}
	while (len > (ptr[0] == '-'))
	{
		ptr[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ptr);
}
