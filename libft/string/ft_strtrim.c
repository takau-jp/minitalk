/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 09:04:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:58:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ft_string.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	bool	trim_set[UCHAR_MAX + 1];
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	ft_bzero(trim_set, sizeof(bool) * (UCHAR_MAX + 1));
	while (*set)
		trim_set[(unsigned char)*(set++)] = true;
	while (*s1 && trim_set[(unsigned char)*s1] == true)
		s1++;
	len = ft_strlen(s1);
	while (len && trim_set[(unsigned char)*(s1 + len - 1)] == true)
		len--;
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len + 1);
	return (s);
}
