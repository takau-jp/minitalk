/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point_internal.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:52:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 00:38:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATING_POINT_INTERNAL_H
# define FLOATING_POINT_INTERNAL_H

// # include <float.h>
/*
#include <unicode/utypes.h> is workaround for #include <float.h>
due to norminette=3.3.55 bug.
*/
# include <unicode/utypes.h>

# include <stdint.h>
# include <stdbool.h>

# include "ft_printf/types.h"

// IEEE754 binary64
# define BINARY64_SIZE 64
# define BINARY64_SIGN 1
# define BINARY64_EXPONENT 11
# define BINARY64_FRACTION 52
# define BINARY64_EMAX 1023
# define BINARY64_NAN_INF 2047

// BINARY64_INT_DIGITS: BINARY64_MAX = 1.80×10^308
# define BINARY64_INT_DIGITS 309
// BINARY64_FRAC_DIGITS: -(52 + 1) + (-1022 + 1) = -1074
# define BINARY64_FRAC_DIGITS 1074
// BINARY64_HEX_INT_DIGIT: 1bit -> 0 or 1
# define BINARY64_HEX_INT_DIGIT 1
// BINARY64_HEX_FRAC_DIGITS: 52bit / 4bit = 13
# define BINARY64_HEX_FRAC_DIGITS 13

// binary80
# define BINARY80_SIZE 80
# define BINARY80_SIGN 1
# define BINARY80_EXPONENT 15
# define BINARY80_FRACTION 63
# define BINARY80_EMAX 16383
# define BINARY80_NAN_INF 32767

// BINARY80_INT_DIGITS: BINARY80_MAX = 1.19×10^4932
# define BINARY80_INT_DIGITS 4933

// BINARY80_FRAC_DIGITS: -64 + (-16382 + 1) = -16445
# define BINARY80_FRAC_DIGITS 16445

// BINARY80_HEX_FRAC_DIGITS: 63bit / 4bit = 15.75
# define BINARY80_HEX_FRAC_DIGITS 16
# if LBINARY64_MANT_DIG == 113
#  error "binary128 has not been implemented."
// binary128
#  define BINARY128_SIZE 128
#  define BINARY128_SIGN 1
#  define BINARY128_EXPONENT 15
#  define BINARY128_FRACTION 112
#  define BINARY128_EMAX 16383
#  define BINARY128_NAN_INF 32767

// BINARY128_INT_DIGITS: BINARY128_MAX = 1.19×10^4932
#  define BINARY128_INT_DIGITS 4933

// BINARY128_FRAC_DIGITS: -(112 + 1) + (-16382 + 1) = -16494
#  define BINARY128_FRAC_DIGITS 16494

// BINARY128_HEX_FRAC_DIGITS: 112bit / 4bit = 28
#  define BINARY128_HEX_FRAC_DIGITS 28
# endif

enum e_pf_float_value_type
{
	FLOAT_ZERO,
	FLOAT_NORMAL,
	FLOAT_SUBNORMAL,
	FLOAT_INF,
	FLOAT_NAN,
};

/*
binary64 or binary80

print_buf layout: [int_part: buf_int_size][frac_part: buf_frac_size]
radix_point = print_buf + buf_int_size
  radix_point[n]  (n >= 0): n-th digit after the decimal point
  radix_point[-n] (n >  0): n-th digit before the decimal point (integer part)
This layout allows carry to propagate across the decimal point without branching.
*/
typedef struct s_floating_point
{
	// bit
	uint8_t						sign;
	int16_t						exponent;
	uint64_t					fraction;
	uint64_t					significand;
	uint64_t					int_binary;
	uint64_t					frac_binary;
	// print
	uint8_t						*print_buf;
	uint8_t						*radix_point;
	// metadata
	uint8_t						base;
	uint8_t						type_bit_size;
	uint8_t						sign_size;
	uint8_t						exponent_size;
	uint8_t						fraction_size;
	uint16_t					emax;
	uint16_t					nan_inf_exponent;
	enum e_pf_float_value_type	value_type;
	uint16_t					buf_size;
	uint16_t					buf_int_size;
	uint16_t					buf_frac_size;
}	t_pf_float;

bool	pf_convert_to_decimal(t_pf_float *fp);
void	pf_convert_to_hex(t_pf_float *fp);
void	pf_decode_binary64(double num, t_pf_float *fp);
void	pf_decode_binary80(long double num, t_pf_float *fp);
void	pf_print_conv_a(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_conv_e(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_conv_f(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_conv_g_exp_notation(
			t_ctx *ctx, t_conv *conv, t_pf_float *fp, int decimal_exp);
void	pf_print_conv_g_fixed_point(
			t_ctx *ctx, t_conv *conv, t_pf_float *fp, int decimal_exp);
void	pf_round_to_nearest_even(t_pf_float *fp, int precision);
// utils
void	pf_array_add(uint8_t *augend, uint8_t *addend, int array_size);
void	pf_array_half(uint8_t *dividend, int array_size);
void	pf_array_double(uint8_t *multiplicand, int array_size);
void	pf_array_double_hex(uint8_t *multiplicand, int array_size);
int		pf_get_decimal_exponent(t_pf_float *fp);
void	pf_print_decimal_exponent(t_ctx *ctx, t_conv *conv, int decimal_exp);
void	pf_print_binary_exponent(t_ctx *ctx, t_conv *conv, int binary_exp);
void	pf_print_inf(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
void	pf_print_nan(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
bool	pf_float_init(t_pf_float *fp, uint16_t type_bit_size, uint8_t base);
void	pf_float_destroy(t_pf_float *fp);

#endif
