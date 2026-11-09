/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 22:58:30 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/18 16:07:24 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_skip_sep(const char *s, char c, int option)
{
	size_t	skiped;

	skiped = 0;
	if (option)
		while (*(s + skiped) && *(s + skiped) == c)
			skiped++;
	else
		while (*(s + skiped) && *(s + skiped) != c)
			skiped++;
	return (skiped);
}

static size_t	ft_len_words(const char *s, char c)
{
	size_t	l_words;

	l_words = 0;
	while (*s)
	{
		s += ft_skip_sep(s, c, 1);
		if (*s)
		{
			l_words++;
			s += ft_skip_sep(s, c, 0);
		}
	}
	return (l_words);
}

static void	ft_free_all(char **buf, int i)
{
	while (i >= 0)
		free(buf[i--]);
	free(buf);
}

static char	**ft_fill_words(char **buf, const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		s += ft_skip_sep(s, c, 1);
		if (*s)
		{
			len = ft_skip_sep(s, c, 0);
			buf[i] = ft_substr(s, 0, len);
			if (!buf[i])
			{
				ft_free_all(buf, (int)i - 1);
				return (NULL);
			}
			s += len;
		}
		i++;
	}
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	size_t	l_words;
	char	**buf;

	if (!s)
		return (NULL);
	l_words = ft_len_words(s, c);
	buf = ft_calloc(l_words + 1, sizeof(char *));
	if (!buf)
		return (NULL);
	return (ft_fill_words(buf, s, c));
}
