/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_scan_literal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:35:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 21:50:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

/*
When the result is NaN,
the most significant bit of the fraction is the quiet bit.
*/
bool	strtod_scan_literal_nan(const char **nptr, t_to_double *to_double)
{
	size_t	i;

	if (ft_tolower((*nptr)[0]) == 'n' \
		&& ft_tolower((*nptr)[1]) == 'a' \
		&& ft_tolower((*nptr)[2]) == 'n')
	{
		*nptr += 3;
		strtod_set_sign(to_double);
		to_double->exp = DBL_NAN_INF_EXP;
		to_double->frac = (1ULL << DBL_NAN_QUIET_BIT);
		i = 0;
		if ((*nptr)[i++] == '(')
		{
			while (ft_isalnum((*nptr)[i]) || (*nptr)[i] == '_')
				++i;
			if ((*nptr)[i] == ')')
			{
				to_double->frac |= ft_strtol(*nptr + 1, NULL, 0) \
										& ((1ULL << DBL_NAN_QUIET_BIT) - 1);
				*nptr = &((*nptr)[i + 1]);
			}
		}
		return (true);
	}
	return (false);
}

bool	strtod_scan_literal_inf(const char **nptr, t_to_double *to_double)
{
	if (ft_tolower((*nptr)[0]) == 'i' \
		&& ft_tolower((*nptr)[1]) == 'n' \
		&& ft_tolower((*nptr)[2]) == 'f')
	{
		*nptr += 3;
		strtod_set_sign(to_double);
		to_double->exp = DBL_NAN_INF_EXP;
		to_double->frac = 0;
		if (ft_tolower((*nptr)[0]) == 'i' \
			&& ft_tolower((*nptr)[1]) == 'n' \
			&& ft_tolower((*nptr)[2]) == 'i' \
			&& ft_tolower((*nptr)[3]) == 't' \
			&& ft_tolower((*nptr)[4]) == 'y')
		{
			*nptr += 5;
		}
		return (true);
	}
	return (false);
}
