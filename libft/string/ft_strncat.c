/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:04:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/18 03:30:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;

	d = dest;
	while (*d)
		d++;
	while (n-- && *src)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}
