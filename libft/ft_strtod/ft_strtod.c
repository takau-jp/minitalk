/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 00:33:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 22:11:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_ctype.h"
#include "ft_string.h"
#include "./ft_strtod_internal.h"

static void		init_to_double(t_to_double *to_double);
static bool		scan_string(\
					const char **nptr, char **ptr, t_to_double *to_double);
static double	encode_to_double(t_to_double *to_double);

double	ft_strtod(const char *nptr, char **endptr)
{
	t_to_double	to_double;
	char		*ptr;

	init_to_double(&to_double);
	ptr = (char *)nptr;
	if (scan_string(&nptr, &ptr, &to_double))
	{
		strtod_set_msd_and_lsd(&to_double);
		strtod_set_sign(&to_double);
		strtod_set_exponent(&to_double);
		strtod_set_fraction(&to_double);
	}
	if (endptr != NULL)
		*endptr = ptr;
	return (encode_to_double(&to_double));
}

static void	init_to_double(t_to_double *to_double)
{
	ft_bzero(to_double, sizeof(t_to_double));
	to_double->ones_digit = &(to_double->fixed_point[INT_DIGITS - 1]);
	to_double->tens_digit = &(to_double->fixed_point[INT_DIGITS]);
	to_double->end = &(to_double->fixed_point[BUF_SIZE - 1]);
}

static bool	scan_string(const char **nptr, char **ptr, t_to_double *to_double)
{
	while (ft_isspace(**nptr))
		++(*nptr);
	strtod_scan_sign(nptr, to_double);
	if (strtod_scan_literal_nan(nptr, to_double) \
		|| strtod_scan_literal_inf(nptr, to_double))
	{
		*ptr = (char *)*nptr;
		return (false);
	}
	strtod_scan_base(nptr, to_double);
	if (!strtod_has_digit(*nptr, to_double))
	{
		if (to_double->base == 10)
			return (false);
		*ptr = (char *)*nptr - 1;
		strtod_set_sign(to_double);
		return (false);
	}
	if (to_double->base == 10)
		strtod_scan_decimal_digits(nptr, to_double);
	else if (to_double->base == 16)
		strtod_scan_hex_digits(nptr, to_double);
	strtod_scan_exponent(nptr, to_double);
	*ptr = (char *)*nptr;
	return (true);
}

static double	encode_to_double(t_to_double *to_double)
{
	union u_double	num;

	num.raw_bits = (to_double->sign << DBL_SIGN_SHIFT) \
					| (to_double->exp << DBL_EXPONENT_SHIFT) \
					| to_double->frac;
	return (num.value);
}
