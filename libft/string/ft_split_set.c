/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:34:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:59:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ft_string.h"

static size_t	count_words(const char *s, bool *set);
static char		**copy_words(\
					const char *s, bool *set, char **dst, size_t count);
static size_t	word_len(const char *s, bool *set);

char	**ft_split_set(const char *s, char *char_set)
{
	char	**dst;
	size_t	count;
	bool	set[UCHAR_MAX + 1];

	if (!s || !char_set)
		return (NULL);
	ft_bzero(set, sizeof(bool) * (UCHAR_MAX + 1));
	while (*char_set)
	{
		set[(unsigned char)(*char_set)] = true;
		char_set++;
	}
	count = count_words(s, set);
	dst = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dst)
		return (NULL);
	dst[count] = NULL;
	return (copy_words(s, set, dst, count));
}

static size_t	count_words(const char *s, bool *set)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (set[(unsigned char)(*s)])
			s++;
		if (*s && !set[(unsigned char)(*s)])
			count++;
		while (*s && !set[(unsigned char)(*s)])
			s++;
	}
	return (count);
}

static char	**copy_words(const char *s, bool *set, char **dst, size_t count)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (count--)
	{
		while (*s && set[(unsigned char)(*s)])
			s++;
		len = word_len(s, set);
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

static size_t	word_len(const char *s, bool *set)
{
	size_t	len;

	len = 0;
	while (s[len] && !set[(unsigned char)s[len]])
		len++;
	return (len);
}
