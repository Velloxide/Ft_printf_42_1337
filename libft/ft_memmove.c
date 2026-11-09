/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:52:33 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/23 12:19:01 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy_from_end(char *d, const char *s, size_t n)
{
	while (n--)
		d[n] = s[n];
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	if (src < dest && (const char *)src + n > (char *)dest)
		ft_cpy_from_end((char *)dest, (const char *)src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
