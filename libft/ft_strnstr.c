/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:39:06 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/23 14:35:45 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_l;

	if (!little[0])
		return ((char *)big);
	len_l = ft_strlen(little);
	i = 0;
	while (len >= len_l + i && big[i])
	{
		if (!ft_strncmp(big + i, little, len_l))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
