/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_to_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:07:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stdlib.h"
#include "ft_printf/ft_printf.h"
#include "./floating_point_internal.h"

static bool	convert_to_decimal_int(t_pf_float *fp);
static bool	convert_to_decimal_frac(t_pf_float *fp);

bool	pf_convert_to_decimal(t_pf_float *fp)
{
	if (!convert_to_decimal_int(fp))
		return (false);
	if (!convert_to_decimal_frac(fp))
		return (false);
	return (true);
}

/* The scaling_factor array, used for converting to decimal, stores powers of 2
	(i.e., 2⁰, 2¹, 2², ...), beginning with 2⁰ = 1.*/
static bool	convert_to_decimal_int(t_pf_float *fp)
{
	uint8_t	*scaling_factor;
	int		n;

	if (fp->exponent < 0)
		return (true);
	scaling_factor = ft_calloc(fp->buf_int_size, sizeof(uint8_t));
	if (scaling_factor == NULL)
		return (false);
	scaling_factor[fp->buf_int_size - 1] = 1;
	n = 0;
	while (n < fp->fraction_size + 1)
	{
		if (fp->int_binary & ((uint64_t)1 << n))
			pf_array_add(fp->print_buf, scaling_factor, fp->buf_int_size);
		pf_array_double(scaling_factor, fp->buf_int_size);
		n++;
	}
	while (n <= fp->exponent)
	{
		pf_array_double(fp->print_buf, fp->buf_int_size);
		n++;
	}
	free(scaling_factor);
	return (true);
}

/* The scaling_factor array, used for converting to decimal, stores powers of 2
	(i.e., 2^-1, 2^-2, 2^-3, ...), beginning with 2^-1 = 0.5.*/
static bool	convert_to_decimal_frac(t_pf_float *fp)
{
	uint8_t	*scaling_factor;
	int		n;

	if (fp->fraction_size < fp->exponent - fp->emax)
		return (true);
	scaling_factor = ft_calloc(fp->buf_frac_size, sizeof(uint8_t));
	if (scaling_factor == NULL)
		return (false);
	scaling_factor[0] = 5;
	n = fp->exponent;
	while (n++ < -1)
		pf_array_half(scaling_factor, fp->buf_frac_size);
	n = 0;
	while (n <= fp->fraction_size)
	{
		if (fp->frac_binary & ((uint64_t)1 << (63 - n)))
			pf_array_add(fp->radix_point, scaling_factor, fp->buf_frac_size);
		pf_array_half(scaling_factor, fp->buf_frac_size);
		n++;
	}
	free(scaling_factor);
	return (true);
}
