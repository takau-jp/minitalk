/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_int_overflow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:18:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:10:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

#include "ft_ctype.h"

bool	pf_check_int_overflow(const char *format)
{
	long	n;

	n = 0;
	while (ft_isdigit(*format))
	{
		n = n * 10 + (*format - '0');
		if (INT_MAX < n)
			return (true);
		format++;
	}
	return (false);
}
