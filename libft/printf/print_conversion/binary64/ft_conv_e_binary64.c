/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e_binary64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:51:40 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_e(t_printf_ctx *ctx, t_my_double *my_double);
static size_t	ft_get_length_exp_notation(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static void		ft_print_exp_notation_non_negative_exp(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static void		ft_print_exp_notation_negative_exp(t_printf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);

void	ft_conv_e_binary64(va_list *ap, t_printf_ctx *ctx)
{
	double		num;
	t_my_double	my_double;

	if (ctx->has_prec == false)
		ctx->precision = 6;
	num = va_arg(*ap, double);
	if (!ft_init_my_double(&my_double))
	{
		ctx->res = -1;
		return ;
	}
	ft_decode_binary64(num, &my_double);
	if (!ft_convert_to_decimal_binary64(&my_double))
	{
		ctx->res = -1;
		ft_free_my_double(&my_double);
		return ;
	}
	ft_round_to_nearest_even_exp_notation_binary64(&my_double, ctx->precision);
	if (my_double.exponent == DBL_NAN_INF)
		ft_print_nan_inf_binary64(ctx, &my_double);
	else
		ft_print_e(ctx, &my_double);
	ft_free_my_double(&my_double);
}

static void	ft_print_e(t_printf_ctx *ctx, t_my_double *my_double)
{
	int		decimal_exp;
	size_t	len;

	decimal_exp = ft_get_decimal_exponent_binary64(my_double);
	len = ft_get_length_exp_notation(ctx, my_double, decimal_exp);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	ft_print_sign(ctx, my_double->sign);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	if (decimal_exp >= 0)
		ft_print_exp_notation_non_negative_exp(ctx, my_double, decimal_exp);
	else
		ft_print_exp_notation_negative_exp(ctx, my_double, decimal_exp);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static size_t	ft_get_length_exp_notation(
					t_printf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	size_t	len;
	size_t	exponent_digits;

	len = 0;
	if (my_double->sign || (my_double->sign == 0 && ctx->sign_flags))
		len += ft_strlen("-");
	len += 1;
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		len += ft_strlen(".");
	len += ctx->precision;
	exponent_digits = 0;
	while (decimal_exp)
	{
		exponent_digits++;
		decimal_exp /= 10;
	}
	if (exponent_digits < 2)
		exponent_digits = 2;
	len += ft_strlen("e+") + exponent_digits;
	return (len);
}

static void	ft_print_exp_notation_non_negative_exp(
				t_printf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;
	int	precision;

	i = 0;
	while (i < PF_DBL_INT && my_double->decimal_int[i] == 0)
		i++;
	ft_xprint_char(ctx, my_double->decimal_int[i++] + '0');
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		ft_xprint_char(ctx, '.');
	precision = ctx->precision;
	while (precision && i < PF_DBL_INT)
	{
		ft_xprint_char(ctx, my_double->decimal_int[i++] + '0');
		precision--;
	}
	i = 0;
	while (precision && i < PF_DBL_FRAC)
	{
		ft_xprint_char(ctx, my_double->decimal_frac[i++] + '0');
		precision--;
	}
	while (precision--)
		ft_xprint_char(ctx, '0');
	ft_print_exponent(ctx, decimal_exp);
}

static void	ft_print_exp_notation_negative_exp(
				t_printf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;
	int	precision;

	i = 0;
	while (i < PF_DBL_FRAC - 1 && my_double->decimal_frac[i] == 0)
		i++;
	ft_xprint_char(ctx, my_double->decimal_frac[i++] + '0');
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		ft_xprint_char(ctx, '.');
	precision = ctx->precision;
	while (precision && i < PF_DBL_FRAC)
	{
		ft_xprint_char(ctx, my_double->decimal_frac[i++] + '0');
		precision--;
	}
	while (precision--)
		ft_xprint_char(ctx, '0');
	ft_print_exponent(ctx, decimal_exp);
}
