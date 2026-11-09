/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 23:33:30 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/23 14:21:22 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len_s;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
