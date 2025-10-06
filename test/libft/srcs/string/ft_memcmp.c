/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:53:10 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:05:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*mem1;
	const unsigned char	*mem2;

	mem1 = s1;
	mem2 = s2;
	if (!n)
		return (0);
	while (n--)
	{
		if (*mem1 != *mem2)
			return (*mem1 - *mem2);
		mem1++;
		mem2++;
	}
	return (0);
}
