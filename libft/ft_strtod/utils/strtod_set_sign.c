/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_set_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:02:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 15:57:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "../ft_strtod_internal.h"

void	strtod_set_sign(t_to_double *to_double)
{
	if (to_double->is_negative)
		to_double->sign = (uint64_t)1;
}
