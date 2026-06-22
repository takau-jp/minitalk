/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_set_msd_and_lsd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:01:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 22:57:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_strtod_internal.h"

void	strtod_set_msd_and_lsd(t_to_double *to_double)
{
	size_t	i;

	i = 0;
	while (i < BUF_SIZE)
	{
		if (to_double->fixed_point[i] != 0)
		{
			if (to_double->msd == NULL)
				to_double->msd = &(to_double->fixed_point[i]);
			to_double->lsd = &(to_double->fixed_point[i]);
		}
		++i;
	}
}
