/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:34:48 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/29 08:27:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		**copy_words(char const *s, char c, char **dst, size_t count);
static size_t	word_len(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	dst = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dst)
		return (NULL);
	dst[count] = NULL;
	return (copy_words(s, c, dst, count));
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**copy_words(char const *s, char c, char **dst, size_t count)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (count--)
	{
		while (*s && *s == c)
			s++;
		len = word_len(s, c);
		dst[i] = (char *)malloc(len + 1);
		if (!dst[i])
		{
			while (i)
				free(dst[--i]);
			free(dst);
			return (NULL);
		}
		ft_strlcpy(dst[i++], s, len + 1);
		s += len;
	}
	return (dst);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}
