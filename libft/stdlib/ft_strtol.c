/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:47:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 00:25:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

#include "ft_ctype.h"
#include "ft_string.h"
#include "ft_stdlib.h"

static bool	scan_base(const char **nptr, const char **ptr, int *base);
static long	scan_num_base(\
	const char **nptr, const char **ptr, int base, bool is_negative);
static int	convert_to_decimal_digit(char c, int base);
static bool	is_long_limit(\
	unsigned long num, int digit, int base, bool is_negative);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long		num;
	const char	*ptr;
	bool		is_negative;

	ptr = nptr;
	while (ft_isspace(*nptr))
		++nptr;
	is_negative = false;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*(nptr) == '-')
			is_negative = true;
		++nptr;
	}
	if (scan_base(&nptr, &ptr, &base))
		num = scan_num_base(&nptr, &ptr, base, is_negative);
	else
		num = 0;
	if (endptr != NULL)
		*endptr = (char *)ptr;
	return (num);
}

static bool	scan_base(const char **nptr, const char **ptr, int *base)
{
	if (*base != 0 && (*base < 2 || 36 < *base))
		return (false);
	if (*base == 0 || *base == 16)
	{
		if (ft_strncmp("0x", *nptr, 2) == 0 \
			|| ft_strncmp("0X", *nptr, 2) == 0)
		{
			*base = 16;
			*ptr = ++(*nptr);
			++(*nptr);
		}
	}
	if (*base == 0 || *base == 8)
	{
		if (ft_strncmp("0", *nptr, 1) == 0)
		{
			*base = 8;
			*ptr = ++(*nptr);
		}
	}
	if (*base == 0)
		*base = 10;
	return (true);
}

static long	scan_num_base(\
	const char **nptr, const char **ptr, int base, bool is_negative)
{
	unsigned long	num;
	int				digit;

	num = 0;
	while (true)
	{
		digit = convert_to_decimal_digit(**nptr, base);
		if (digit == -1)
			break ;
		*ptr = ++(*nptr);
		if (is_long_limit(num, digit, base, is_negative))
		{
			if (is_negative)
				num = ft_abs_ulong(LONG_MIN);
			else
				num = LONG_MAX;
		}
		else
			num = num * base + digit;
	}
	if (num == ft_abs_ulong(LONG_MIN))
		return (LONG_MIN);
	if (is_negative)
		return (-((long)num));
	return ((long)num);
}

static int	convert_to_decimal_digit(char c, int base)
{
	if (ft_isdigit(c))
	{
		if (c - '0' < base)
			return (c - '0');
	}
	else if (ft_isupper(c))
	{
		if (c - 'A' < base - 10)
			return (c - 'A' + 10);
	}
	else if (ft_islower(c))
	{
		if (c - 'a' < base - 10)
			return (c - 'a' + 10);
	}
	return (-1);
}

static bool	is_long_limit(\
	unsigned long num, int digit, int base, bool is_negative)
{
	if (num > (unsigned long)LONG_MAX / base)
		return (true);
	else if (num == (unsigned long)LONG_MAX / base)
	{
		if (is_negative)
			return (digit >= (int)(ft_abs_ulong(LONG_MIN) % base));
		else
			return (digit >= (int)(LONG_MAX % base));
	}
	return (false);
}
