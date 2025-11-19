/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:34:48 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/12 15:25:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, bool set[256]);
static char		**copy_words(\
					char const *s, bool set[256], char **dst, size_t count);
static size_t	word_len(char const *s, bool set[256]);

char	**ft_split_set(char const *s, char *char_set)
{
	char	**dst;
	size_t	count;
	bool	set[256];
	size_t	i;

	if (!s || !char_set)
		return (NULL);
	i = 0;
	while (i < 256)
	{
		set[i] = false;
		i++;
	}
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

static size_t	count_words(char const *s, bool set[256])
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

static char	**copy_words(
	char const *s, bool set[256], char **dst, size_t count)
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

static size_t	word_len(char const *s, bool set[256])
{
	size_t	len;

	len = 0;
	while (s[len] && !set[(unsigned char)s[len]])
		len++;
	return (len);
}
