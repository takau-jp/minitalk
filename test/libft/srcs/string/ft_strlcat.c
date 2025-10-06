/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:40:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/04/29 20:21:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;

	dstlen = ft_strnlen(dst, size);
	if (dstlen == size)
		return (dstlen + ft_strlen(src));
	return (dstlen + ft_strlcpy(dst + dstlen, src, size - dstlen));
}
