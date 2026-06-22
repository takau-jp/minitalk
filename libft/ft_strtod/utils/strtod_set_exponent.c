/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_set_exponent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:01:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 22:08:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "../ft_strtod_internal.h"

static bool	is_normalized(t_to_double *to_double);

void	strtod_set_exponent(t_to_double *to_double)
{
	to_double->exp = DBL_EMAX;
	if (to_double->is_inf)
		to_double->exp = DBL_NAN_INF_EXP;
	else if (to_double->msd == NULL)
		to_double->exp = 0;
	else if (to_double->msd <= to_double->ones_digit)
	{
		while (to_double->exp < DBL_NAN_INF_EXP && !is_normalized(to_double))
		{
			if (*(to_double->end) % 2 == 1)
				to_double->has_sticky = true;
			strtod_half_array(to_double);
			++(to_double->exp);
		}
	}
	else
	{
		while (to_double->exp > 1 && !is_normalized(to_double))
		{
			strtod_double_array(to_double);
			--(to_double->exp);
		}
		if (to_double->tens_digit <= to_double->msd)
			to_double->exp = 0;
	}
}

static bool	is_normalized(t_to_double *to_double)
{
	return (*(to_double->ones_digit) == 1 \
				&& to_double->msd == to_double->ones_digit);
}
