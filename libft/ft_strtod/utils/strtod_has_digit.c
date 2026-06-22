/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_has_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:00:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 20:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "../ft_strtod_internal.h"

bool	strtod_has_digit(const char *nptr, t_to_double *to_double)
{
	if (*nptr == '.')
		++nptr;
	if (to_double->base == 16)
		return (ft_isxdigit(*nptr));
	return (ft_isdigit(*nptr));
}
