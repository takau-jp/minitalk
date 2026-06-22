/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:42:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:40:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

// Linear Congruential Generator, LCG (Park & Miller)
int	ft_rand_r(unsigned int *seed)
{
	uint64_t	x;

	if (*seed == 0)
		*seed = 1;
	x = (uint64_t)(*seed) * (uint64_t)48271;
	x = (x % (uint64_t)2147483647);
	*seed = (unsigned int)x;
	return (*seed);
}
