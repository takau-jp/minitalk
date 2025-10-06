/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_a_binary64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:51:38 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:07:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void		ft_print_a(t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex);
static int		ft_get_printable_precision_hex(
					t_my_double_hex *my_double_hex);
static size_t	ft_get_length_float_hex(
					t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex);
static void		ft_print_float_hex(
					t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex);

void	ft_conv_a_binary64(va_list *ap, t_dprintf_ctx *ctx)
{
	double			num;
	t_my_double_hex	my_double_hex;

	if (ctx->has_prec == false)
		ctx->precision = PF_DBL_FRAC_HEX;
	num = va_arg(*ap, double);
	ft_bzero(&my_double_hex, sizeof(my_double_hex));
	ft_decode_hex_binary64(num, &my_double_hex);
	ft_convert_to_hex_binary64(&my_double_hex);
	ft_round_to_nearest_even_hex_binary64(&my_double_hex, ctx->precision);
	if (my_double_hex.exponent == DBL_NAN_INF)
		ft_print_nan_inf_hex_binary64(ctx, &my_double_hex);
	else
		ft_print_a(ctx, &my_double_hex);
}

static void	ft_print_a(t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex)
{
	size_t	len;

	if (!ctx->has_prec && !ctx->hash_flag)
		ctx->precision = ft_get_printable_precision_hex(my_double_hex);
	len = ft_get_length_float_hex(ctx, my_double_hex);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	ft_print_sign(ctx, my_double_hex->sign);
	ft_print_hexa_preffix(ctx);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	ft_print_float_hex(ctx, my_double_hex);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static int	ft_get_printable_precision_hex(
				t_my_double_hex *my_double_hex)
{
	int	i;
	int	printable_prec;

	i = 0;
	printable_prec = 0;
	while (i < PF_DBL_FRAC_HEX)
	{
		if (my_double_hex->hex_frac[i++] != 0)
			printable_prec = i;
	}
	return (printable_prec);
}

static size_t	ft_get_length_float_hex(
					t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex)
{
	size_t	len;
	int		exp;
	size_t	exponent_digits;

	len = 0;
	if (my_double_hex->sign || (my_double_hex->sign == 0 && ctx->sign_flags))
		len += ft_strlen("-");
	len += ft_strlen("0x") + 1;
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		len += ft_strlen(".");
	len += ctx->precision;
	if (my_double_hex->exponent == 0)
		exp = 1 - DBL_EMAX;
	else
		exp = my_double_hex->exponent - DBL_EMAX;
	exponent_digits = 0;
	while (exp)
	{
		exponent_digits++;
		exp /= 10;
	}
	if (exponent_digits == 0)
		exponent_digits = 1;
	len += ft_strlen("p+") + exponent_digits;
	return (len);
}

static void	ft_print_float_hex(
				t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex)
{
	int	i;
	int	precision;
	int	exp;

	ft_dprint_char(ctx, my_double_hex->hex_int + '0');
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		ft_dprint_char(ctx, '.');
	precision = ctx->precision;
	i = 0;
	while (precision && i < PF_DBL_FRAC_HEX)
	{
		if (ctx->conv == 'a')
			ft_dprint_char(ctx, "0123456789abcdef"[my_double_hex->hex_frac[i]]);
		else
			ft_dprint_char(ctx, "0123456789ABCDEF"[my_double_hex->hex_frac[i]]);
		i++;
		precision--;
	}
	while (precision--)
		ft_dprint_char(ctx, '0');
	if (my_double_hex->exponent == 0)
		exp = 1 - DBL_EMAX;
	else
		exp = my_double_hex->exponent - DBL_EMAX;
	ft_print_exponent_hex(ctx, exp);
}
