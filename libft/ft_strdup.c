/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:05:41 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/17 13:32:55 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len_s;

	len_s = ft_strlen(s);
	ptr = ft_calloc(len_s + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s, len_s);
	return (ptr);
}
