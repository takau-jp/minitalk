/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_scan_exponent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:00:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 20:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

void	strtod_scan_exponent(const char **nptr, t_to_double *to_double)
{
	const char	*p;
	char		*end;

	if (to_double->base == 10 \
		&& (**nptr == 'e' || **nptr == 'E') && !ft_isspace(*(*nptr + 1)))
	{
		p = *nptr + 1;
	}
	else if (to_double->base == 16 \
		&& (**nptr == 'p' || **nptr == 'P') && !ft_isspace(*(*nptr + 1)))
	{
		p = *nptr + 1;
	}
	else
		return ;
	ft_strtol(p, &end, 10);
	if (end != p)
		*nptr = end;
}
