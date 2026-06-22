/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_scan_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:01:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 20:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_strtod_internal.h"

void	strtod_scan_sign(const char **nptr, t_to_double *to_double)
{
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			to_double->is_negative = true;
		++(*nptr);
	}
}
