/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decode_binary80.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:31:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 16:19:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "./floating_point_internal.h"

static void	set_float_value_type(t_pf_float *fp);
static void	get_int_binary(t_pf_float *fp);
static void	get_frac_binary(t_pf_float *fp);

// Little endian assumption: first get right, then left
void	pf_decode_binary80(long double num, t_pf_float *fp)
{
	uint64_t	right_mem;
	uint16_t	left_mem;

	ft_memcpy(&(right_mem), (char *)&num, sizeof(uint64_t));
	ft_memcpy(&(left_mem), (char *)&num + sizeof(uint64_t), sizeof(uint16_t));
	fp->sign = (left_mem >> (fp->exponent_size)) & (uint16_t)1;
	fp->exponent = left_mem & (((uint16_t)1 << fp->exponent_size) - 1);
	fp->fraction = right_mem & (((uint64_t)1 << fp->fraction_size) - 1);
	fp->significand = right_mem;
	set_float_value_type(fp);
	if (fp->value_type == FLOAT_INF || fp->value_type == FLOAT_NAN)
		return ;
	if (fp->value_type == FLOAT_SUBNORMAL)
		fp->emax -= 1;
	if (fp->value_type != FLOAT_ZERO)
		fp->exponent = (int16_t)(fp->exponent - fp->emax);
	get_int_binary(fp);
	get_frac_binary(fp);
}

// Pseudo-denormal treated as subnormal
static void	set_float_value_type(t_pf_float *fp)
{
	if (fp->exponent == fp->nan_inf_exponent)
	{
		if (fp->fraction == 0)
			fp->value_type = FLOAT_INF;
		else
			fp->value_type = FLOAT_NAN;
	}
	else if (fp->exponent == 0)
	{
		if (fp->significand == 0)
			fp->value_type = FLOAT_ZERO;
		else
			fp->value_type = FLOAT_SUBNORMAL;
	}
	else
		fp->value_type = FLOAT_NORMAL;
}

static void	get_int_binary(t_pf_float *fp)
{
	int	offset;

	if (fp->exponent < 0)
	{
		fp->int_binary = 0;
		return ;
	}
	if (fp->exponent <= fp->fraction_size)
		offset = fp->exponent;
	else
		offset = fp->fraction_size;
	fp->int_binary = fp->significand >> (fp->fraction_size - offset);
}

/*
Packs the fractional bits of the significand into frac_binary such that
bit 63 of frac_binary is the first fractional bit (representing 2^-1).
When exponent >= 0, offset += exponent skips the bits already consumed by
the integer part, placing the next fractional bit at bit 63.
When exponent < 0, the entire significand including the implicit leading 1
is fractional. Subtracting 1 from offset places that leading 1 at bit 63.
*/
static void	get_frac_binary(t_pf_float *fp)
{
	int	offset;

	if (fp->fraction_size <= fp->exponent)
	{
		fp->frac_binary = 0;
		return ;
	}
	offset = 64 - fp->fraction_size;
	if (fp->exponent < 0)
		offset -= 1;
	else
		offset += fp->exponent;
	fp->frac_binary = fp->significand << offset;
}
