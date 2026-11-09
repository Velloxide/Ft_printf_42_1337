/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:47:21 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/17 17:17:58 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_s;
	size_t	total_size;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	total_size = len_s - start;
	if (len < total_size)
		total_size = len;
	ptr = ft_calloc((total_size + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (s + start), total_size + 1);
	return (ptr);
}
