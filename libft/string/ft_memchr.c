/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:22:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/23 01:55:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;

	mem = s;
	c = (unsigned char)c;
	while (n--)
	{
		if (*mem == c)
			return ((void *)mem);
		mem++;
	}
	return (NULL);
}
