/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:04:13 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:06:54 by stanaka2         ###   ########.fr       */
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
