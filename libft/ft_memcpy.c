/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:18:17 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/23 11:12:47 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d2;
	const char	*s2;

	d2 = (char *)dest;
	s2 = (const char *)src;
	while (n--)
		*d2++ = *s2++;
	return (dest);
}
