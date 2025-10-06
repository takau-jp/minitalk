/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:56:48 by stanaka2          #+#    #+#             */
/*   Updated: 2025/05/01 11:32:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	char	*dst;

	n = ft_strnlen(s1, n);
	dst = (char *)malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, n + 1);
	return (dst);
}
