/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:15:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./floating_point_internal.h"

static void	convert_to_hex_int(t_pf_float *fp);
static void	convert_to_hex_frac(t_pf_float *fp);

void	pf_convert_to_hex(t_pf_float *fp)
{
	convert_to_hex_int(fp);
	convert_to_hex_frac(fp);
}

static void	convert_to_hex_int(t_pf_float *fp)
{
	if (fp->value_type == FLOAT_NORMAL)
		fp->radix_point[-1] = 1;
	else
		fp->radix_point[-1] = 0;
}

static void	convert_to_hex_frac(t_pf_float *fp)
{
	int64_t	bit_mask;
	int		i;

	bit_mask = 0x0F;
	i = 0;
	while (i < fp->buf_frac_size)
	{
		fp->radix_point[i] = (uint8_t)(fp->fraction
				>> (fp->fraction_size - ((i + 1) * 4)) & bit_mask);
		i++;
	}
}
