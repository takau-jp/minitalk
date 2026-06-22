/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_set_fraction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:01:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 22:12:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

#include "../ft_strtod_internal.h"

static void	round_to_nearest_even(t_to_double *to_double);

void	strtod_set_fraction(t_to_double *to_double)
{
	size_t	i;

	if (to_double->exp == DBL_NAN_INF_EXP || to_double->msd == NULL)
	{
		to_double->frac = 0;
		return ;
	}
	*(to_double->ones_digit) = 0;
	i = 0;
	while (i++ < DBL_FRACTION)
	{
		strtod_double_array(to_double);
		to_double->frac <<= 1;
		if (*(to_double->ones_digit) % 2 == 1)
			to_double->frac |= 1ULL;
	}
	round_to_nearest_even(to_double);
}

static void	round_to_nearest_even(t_to_double *to_double)
{
	uint8_t		half;

	half = to_double->base / 2;
	if (*(to_double->tens_digit) > half \
		|| (*(to_double->tens_digit) == half \
			&& (*(to_double->ones_digit) % 2 == 1
				|| to_double->has_sticky \
				|| to_double->tens_digit < to_double->lsd)))
	{
		++(to_double->frac);
	}
	if (to_double->frac & (1ULL << DBL_FRACTION))
	{
		to_double->frac = 0;
		++(to_double->exp);
	}
}
