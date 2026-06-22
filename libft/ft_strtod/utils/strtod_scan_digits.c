/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_scan_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 03:22:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 15:49:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

#include "ft_ctype.h"
#include "../ft_strtod_internal.h"

static void		add_scaled_hex_digits(\
					t_to_double *to_double, ptrdiff_t i, char c, int8_t mod);
static uint8_t	hex_to_decimal(char c);
static void		add_digit(t_to_double *to_double, ptrdiff_t i, uint8_t digit);

void	strtod_scan_decimal_digits(const char **nptr, t_to_double *to_double)
{
	const long	exponent = strtod_pre_scan_decimal_exponent(*nptr);
	const long	shift = exponent;
	const char	*radix_point;
	ptrdiff_t	i;

	radix_point = *nptr;
	while (ft_isdigit(*radix_point))
		++radix_point;
	i = INT_DIGITS - (radix_point - *nptr);
	while (ft_isdigit(**nptr) || (**nptr == '.' && (radix_point == *nptr)))
	{
		if (**nptr != '0' && **nptr != '.')
		{
			if (0 < shift && LONG_MIN + shift > i)
				to_double->is_inf = true;
			else if (shift < 0 && LONG_MAX + shift < i)
				to_double->has_sticky = true;
			else
				add_digit(to_double, i - shift, **nptr - '0');
		}
		if (**nptr != '.')
			++i;
		++(*nptr);
	}
}

void	strtod_scan_hex_digits(const char **nptr, t_to_double *to_double)
{
	const long		exponent = strtod_pre_scan_hex_exponent(*nptr);
	const long		shift = exponent / 4;
	const int8_t	mod = exponent % 4;
	const char		*radix_point;
	ptrdiff_t		i;

	radix_point = *nptr;
	while (ft_isxdigit(*radix_point))
		++radix_point;
	i = INT_DIGITS - (radix_point - *nptr);
	while (ft_isxdigit(**nptr) || (**nptr == '.' && (radix_point == *nptr)))
	{
		if (**nptr != '0' && **nptr != '.')
		{
			if (0 < shift && LONG_MIN + shift > i)
				to_double->is_inf = true;
			else if (shift < 0 && LONG_MAX + shift < i)
				to_double->has_sticky = true;
			else
				add_scaled_hex_digits(to_double, i - shift, **nptr, mod);
		}
		if (**nptr != '.')
			++i;
		++(*nptr);
	}
}

static void	add_scaled_hex_digits(\
	t_to_double *to_double, ptrdiff_t i, char c, int8_t mod)
{
	const uint8_t	n = hex_to_decimal(c);
	uint8_t			power;

	if (mod == 3 || mod == -3)
		power = 8;
	else if (mod == 2 || mod == -2)
		power = 4;
	else
		power = 2;
	if (mod > 0)
	{
		add_digit(to_double, i, (n * power) % 16);
		if (LONG_MIN < i)
			add_digit(to_double, i - 1, (n * power) / 16);
	}
	else if (mod < 0)
	{
		add_digit(to_double, i, n / power);
		if (i < LONG_MAX)
			add_digit(to_double, i + 1, ((n % power) * 16) / power);
	}
	else
		add_digit(to_double, i, n);
}

static uint8_t	hex_to_decimal(char c)
{
	if (ft_isupper(c))
		return (c - 'A' + 10);
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else
		return (c - '0');
}

static void	add_digit(t_to_double *to_double, ptrdiff_t i, uint8_t digit)
{
	uint8_t	*p;

	if (i < 0)
		to_double->is_inf = true;
	else if (BUF_SIZE <= i)
		to_double->has_sticky = true;
	else
	{
		p = &(to_double->fixed_point[i]);
		*p += digit;
		if (*p >= to_double->base)
			add_digit(to_double, i - 1, 1);
		*p %= to_double->base;
	}
}
