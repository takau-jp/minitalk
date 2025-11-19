/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 09:04:58 by stanaka2          #+#    #+#             */
/*   Updated: 2025/04/30 19:47:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	trim_set[256];
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	ft_bzero(trim_set, 256);
	while (*set)
		trim_set[(unsigned char)*set++] = 1;
	while (*s1 && trim_set[(unsigned char)*s1] == 1)
		s1++;
	len = ft_strlen(s1);
	while (len && trim_set[(unsigned char)*(s1 + len - 1)] == 1)
		len--;
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len + 1);
	return (s);
}
