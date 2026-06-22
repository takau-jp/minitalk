/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_t_float_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:52:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string.h"
#include "ft_stdlib.h"
#include "../floating_point_internal.h"

static void	set_binary64_metadata(t_pf_float *fp, uint8_t base);
static void	set_binary80_metadata(t_pf_float *fp);

/*
Allocates print_buf as a single contiguous array of buf_size digits.
radix_point is set to print_buf + buf_int_size, so negative indices
address the integer part and non-negative indices address the fractional part.
*/
bool	pf_float_init(t_pf_float *fp, uint16_t type_bit_size, uint8_t base)
{
	ft_bzero(fp, sizeof(t_pf_float));
	if (type_bit_size == BINARY64_SIZE)
		set_binary64_metadata(fp, base);
	else
		set_binary80_metadata(fp);
	fp->print_buf = ft_calloc(fp->buf_size, sizeof(uint8_t));
	if (fp->print_buf == NULL)
	{
		return (false);
	}
	fp->radix_point = fp->print_buf + fp->buf_int_size;
	return (true);
}

static void	set_binary64_metadata(t_pf_float *fp, uint8_t base)
{
	fp->base = base;
	fp->type_bit_size = BINARY64_SIZE;
	fp->sign_size = BINARY64_SIGN;
	fp->exponent_size = BINARY64_EXPONENT;
	fp->fraction_size = BINARY64_FRACTION;
	fp->emax = BINARY64_EMAX;
	fp->nan_inf_exponent = BINARY64_NAN_INF;
	if (fp->base == 10)
	{
		fp->buf_int_size = BINARY64_INT_DIGITS;
		fp->buf_frac_size = BINARY64_FRAC_DIGITS;
	}
	else
	{
		fp->buf_int_size = BINARY64_HEX_INT_DIGIT;
		fp->buf_frac_size = BINARY64_HEX_FRAC_DIGITS;
	}
	fp->buf_size = fp->buf_int_size + fp->buf_frac_size;
}

static void	set_binary80_metadata(t_pf_float *fp)
{
	fp->base = 10;
	fp->type_bit_size = BINARY80_SIZE;
	fp->sign_size = BINARY80_SIGN;
	fp->exponent_size = BINARY80_EXPONENT;
	fp->fraction_size = BINARY80_FRACTION;
	fp->emax = BINARY80_EMAX;
	fp->nan_inf_exponent = BINARY80_NAN_INF;
	fp->buf_int_size = BINARY80_INT_DIGITS;
	fp->buf_frac_size = BINARY80_FRAC_DIGITS;
	fp->buf_size = fp->buf_int_size + fp->buf_frac_size;
}

void	pf_float_destroy(t_pf_float *fp)
{
	free(fp->print_buf);
}
