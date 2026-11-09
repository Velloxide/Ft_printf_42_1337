/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 23:34:21 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/22 22:08:46 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == s2)
		return (0);
	while (i < n
		&& ((const unsigned char *)s1)[i] == ((const unsigned char *)s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i]);
}
