/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:16:43 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/12 15:26:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <wchar.h>
# include <stdarg.h>
// # include <float.h>
# include "libft.h"

# ifdef __APPLE__
#  ifndef PRINTF_RESULT_LIMIT
#   define PRINTF_RESULT_LIMIT 2147483646
#  endif
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 16384
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE PAGE_SIZE
#  endif
# else
#  define PRINTF_RESULT_LIMIT INT_MAX
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 4096
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE 16384
#  endif
# endif

# define PF_CONV "cspdiuxX%onfFeEgGaA"
# define PF_FLAGS "-+ #0"
# define PF_LENGTH "hljztL"

// IEEE754 binary64
# define DBL_SIZE 64
# define DBL_SIGN 1
# define DBL_EXPONENT 11
# define DBL_FRACTION 52
# define DBL_EMAX 1023
# define DBL_NAN_INF 2047
# define PF_DBL_INT 309
# define PF_DBL_FRAC 1074
# define PF_DBL_FRAC_HEX 13
// PF_DBL_INT: DBL_MAX = 1.80×10^308
// PF_DBL_FRAC: -(52 + 1) + (-1022 + 1) = -1074
// PF_DBL_FRAC_HEX: 52bit / 4bit = 13

# if __LDBL_MANT_DIG__ == 64
// 80bit
#  define LDBL_SIZE 80
#  define LDBL_SIGN 1
#  define LDBL_EXPONENT 15
#  define LDBL_FRACTION 63
#  define LDBL_EMAX 16383
#  define LDBL_NAN_INF 32767
#  define PF_LDBL_INT 4933
#  define PF_LDBL_FRAC 16445
#  define PF_LDBL_FRAC_HEX 16
// PF_LDBL_INT: LDBL_MAX = 1.19×10^4932
// PF_LDBL_FRAC: -64 + (-16382 + 1) = -16445
// PF_LDBL_FRAC_HEX: 63bit / 4bit = 15.75
# else
// binary128
#  define LDBL_SIZE 128
#  define LDBL_SIGN 1
#  define LDBL_EXPONENT 15
#  define LDBL_FRACTION 112
#  define LDBL_EMAX 16383
#  define LDBL_NAN_INF 32767
#  define PF_LDBL_INT 4933
#  define PF_LDBL_FRAC 16494
#  define PF_LDBL_FRAC_HEX 28
// PF_LDBL_INT: LDBL_MAX = 1.19×10^4932
// PF_LDBL_FRAC: -(112 + 1) + (-16382 + 1) = -16494
// PF_LDBL_FRAC_HEX: 112bit / 4bit = 28
# endif

typedef enum e_printf_dst
{
	PRINT_TO_FD,
	PRINT_TO_STR,
}	t_printf_dst;

typedef struct s_printf_ctx
{
	t_printf_dst	dst_type;
	int				fd;
	char			*str;
	size_t			str_size;
	int				res;
	char			conv;
	char			hash_flag;
	char			sign_flags;
	char			width_flags;
	int				width;
	bool			has_prec;
	int				precision;
	char			length[3];
}	t_printf_ctx;

typedef struct s_my_double
{
	uint8_t		sign;
	int16_t		exponent;
	uint64_t	significand;
	uint64_t	int_binary;
	uint64_t	frac_binary;
	int8_t		*decimal_int;
	int8_t		*decimal_frac;
}	t_my_double;

typedef struct s_my_double_hex
{
	uint8_t		sign;
	int16_t		exponent;
	uint64_t	fraction;
	int8_t		hex_int;
	int8_t		hex_frac[PF_DBL_FRAC_HEX];
}	t_my_double_hex;

typedef struct s_my_uint128
{
	uint64_t	left;
	uint64_t	right;
}	t_my_uint128;

typedef struct s_my_longdouble
{
	uint8_t			sign;
	int16_t			exponent;
	t_my_uint128	significand;
	t_my_uint128	int_binary;
	t_my_uint128	frac_binary;
	int8_t			*decimal_int;
	int8_t			*decimal_frac;
}	t_my_longdouble;

typedef struct s_my_longdouble_hex
{
	uint8_t			sign;
	int16_t			exponent;
	t_my_uint128	fraction;
	int8_t			hex_int;
	int8_t			hex_frac[PF_LDBL_FRAC_HEX];
}	t_my_longdouble_hex;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
void			ft_xprint_format(\
					t_printf_ctx *ctx, va_list *ap, const char *format);
void			ft_reset_conversion(t_printf_ctx *ctx);
bool			ft_read_conversion(
					va_list *ap, const char **format, t_printf_ctx *ctx);
bool			ft_check_int_overflow(const char *format);
int				ft_atoi_precision(const char *format);
void			ft_xprint_char(t_printf_ctx *ctx, int c);
void			ft_xprint_strn(t_printf_ctx *ctx, char *s, size_t len);
bool			ft_write_to_fd(int fd, char *s, size_t len);
size_t			ft_min_size(size_t	num1, size_t num2);
void			ft_print_hexa_preffix(t_printf_ctx *ctx);
void			ft_print_conversion(va_list *ap, t_printf_ctx *ctx);
void			ft_print_zero_width(t_printf_ctx *ctx, size_t	len);
void			ft_print_space_width(t_printf_ctx *ctx, size_t len);
void			ft_print_sign(t_printf_ctx *ctx, bool is_negative);
void			ft_print_padding(t_printf_ctx *ctx, size_t padding);
void			ft_conv_c(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_s(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_d_i(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_u(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_x(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_p(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_percent(t_printf_ctx *ctx);
// extra (%o, %n, %f, %e, %g, %a, %Lf, %Le, %Lg, %lc, %ls)
void			ft_conv_o(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_f_e_g(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_a(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_n(va_list *ap, t_printf_ctx *ctx);
// binary64
void			ft_conv_a_binary64(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_e_binary64(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_f_binary64(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_g_binary64(va_list *ap, t_printf_ctx *ctx);
bool			ft_convert_to_decimal_binary64(t_my_double *my_double);
void			ft_convert_to_hex_binary64(t_my_double_hex *my_double_hex);
void			ft_decode_binary64(double num, t_my_double *my_double);
void			ft_decode_hex_binary64(
					double num, t_my_double_hex *my_double_hex);
int				ft_get_decimal_exponent_binary64(t_my_double *my_double);
bool			ft_init_my_double(t_my_double *my_double);
void			ft_free_my_double(t_my_double *my_double);
void			ft_normalize_hex_binary64(t_my_double_hex *my_double_hex);
void			ft_print_g_exp_notation_binary64(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exponent);
void			ft_print_g_fixed_point_binary64(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exponent);
void			ft_print_nan_inf_binary64(
					t_printf_ctx *ctx, t_my_double *my_double);
void			ft_print_nan_inf_hex_binary64(
					t_printf_ctx *ctx, t_my_double_hex *my_double_hex);
void			ft_round_to_nearest_even_binary64(
					t_my_double *my_double, int precision);
void			ft_round_to_nearest_even_exp_notation_binary64(
					t_my_double *my_double, int precision);
void			ft_round_to_nearest_even_hex_binary64(
					t_my_double_hex *my_double_hex, int precision);
// 80bit
void			ft_conv_e_80bit(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_f_80bit(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_g_80bit(va_list *ap, t_printf_ctx *ctx);
bool			ft_convert_to_decimal_80bit(t_my_double *my_double);
void			ft_decode_80bit(long double num, t_my_double *my_double);
int				ft_get_decimal_exponent_80bit(t_my_double *my_double);
bool			ft_init_my_double_80bit(t_my_double *my_double);
void			ft_free_my_double_80bit(t_my_double *my_double);
void			ft_print_g_exp_notation_80bit(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exponent);
void			ft_print_g_fixed_point_80bit(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exponent);
void			ft_print_nan_inf_80bit(
					t_printf_ctx *ctx, t_my_double *my_double);
void			ft_round_to_nearest_even_80bit(
					t_my_double *my_double, int precision);
void			ft_round_to_nearest_even_exp_notation_80bit(
					t_my_double *my_double, int precision);
// float_common_utils
void			ft_array_add(int8_t *augend, int8_t *addend, int array_size);
void			ft_array_half(int8_t *dividend, int array_size);
void			ft_array_double(int8_t *multiplicand, int array_size);
void			ft_array_double_hex(int8_t *multiplicand, int array_size);
void			ft_print_exponent(t_printf_ctx *ctx, int decimal_exponent);
void			ft_print_exponent_hex(t_printf_ctx *ctx, int exp);
// wchar_t to UTF-8
void			ft_conv_lc(va_list *ap, t_printf_ctx *ctx);
void			ft_conv_ls(va_list *ap, t_printf_ctx *ctx);
void			ft_encode_wchar_to_utf8(
					unsigned char utf8[5], const wchar_t wc);
bool			ft_is_utf8_leading_byte(unsigned char byte);
void			ft_print_utf8(
					t_printf_ctx *ctx, unsigned char *utf8_str, size_t len);

#endif
