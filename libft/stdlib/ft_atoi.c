/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:40:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 14:35:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"

static bool	is_long_limit(long num, int sign, int n);

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*(nptr++) == '-')
			sign = -1;
	}
	num = 0;
	while (ft_isdigit(*nptr))
	{
		if (is_long_limit(num, sign, (*nptr - '0')))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(num * sign));
}

static bool	is_long_limit(long num, int sign, int n)
{
	long	limit;

	if (sign == 1)
		limit = LONG_MAX;
	else
		limit = LONG_MIN;
	if (num > LONG_MAX / 10
		|| (num == LONG_MAX / 10 && n >= (int)(ft_abs_ulong(limit) % 10)))
		return (true);
	return (false);
}
