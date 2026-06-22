/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_pre_scan_exponent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:31:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 20:00:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"

long	strtod_pre_scan_decimal_exponent(const char *nptr)
{
	while (ft_isdigit(*nptr))
		++nptr;
	if (*nptr == '.')
		++nptr;
	while (ft_isdigit(*nptr))
		++nptr;
	if ((*nptr == 'e' || *nptr == 'E') && !ft_isspace(*(nptr + 1)))
		return (ft_strtol(nptr + 1, NULL, 10));
	else
		return (0);
}

long	strtod_pre_scan_hex_exponent(const char *nptr)
{
	while (ft_isxdigit(*nptr))
		++nptr;
	if (*nptr == '.')
		++nptr;
	while (ft_isxdigit(*nptr))
		++nptr;
	if ((*nptr == 'p' || *nptr == 'P') && !ft_isspace(*(nptr + 1)))
		return (ft_strtol(nptr + 1, NULL, 10));
	else
		return (0);
}
