/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:18:02 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/19 23:11:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// // default version
// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	unsigned char		*d;
// 	const unsigned char	*s;

// 	d = dst;
// 	s = src;
// 	if (!dst && !src)
// 		return (NULL);
// 	while (n--)
// 		*d++ = *s++;
// 	return (dst);
// }

// scan-build no warning version
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (!dst || !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}
