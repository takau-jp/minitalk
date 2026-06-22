/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_decimal_exponent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:16:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../floating_point_internal.h"

int	pf_get_decimal_exponent(t_pf_float *fp)
{
	int	i;
	int	decimal_exponent;

	if (fp->value_type == FLOAT_ZERO)
		return (0);
	if (fp->int_binary != 0)
	{
		i = 0;
		while (i < fp->buf_int_size && fp->print_buf[i] == 0)
			i++;
		decimal_exponent = fp->buf_int_size - i - 1;
	}
	else
	{
		i = 0;
		while (i < fp->buf_frac_size && fp->radix_point[i] == 0)
			i++;
		decimal_exponent = -(i + 1);
	}
	return (decimal_exponent);
}
