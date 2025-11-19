/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_g_80bit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:51:42 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_g_determine_format(
				t_printf_ctx *ctx, t_my_double *my_double);

void	ft_conv_g_80bit(va_list *ap, t_printf_ctx *ctx)
{
	long double		num;
	t_my_double		my_double;

	if (ctx->has_prec == false)
		ctx->precision = 6;
	if (ctx->has_prec == true && ctx->precision == 0)
		ctx->precision = 1;
	num = va_arg(*ap, long double);
	if (!ft_init_my_double_80bit(&my_double))
	{
		ctx->res = -1;
		return ;
	}
	ft_decode_80bit(num, &my_double);
	if (!ft_convert_to_decimal_80bit(&my_double))
	{
		ctx->res = -1;
		ft_free_my_double_80bit(&my_double);
		return ;
	}
	if (my_double.exponent == LDBL_NAN_INF)
		ft_print_nan_inf_80bit(ctx, &my_double);
	else
		ft_conv_g_determine_format(ctx, &my_double);
	ft_free_my_double_80bit(&my_double);
}

static void	ft_conv_g_determine_format(
				t_printf_ctx *ctx, t_my_double *my_double)
{
	int		decimal_exp;

	ft_round_to_nearest_even_exp_notation_80bit(my_double,
		ctx->precision - 1);
	decimal_exp = ft_get_decimal_exponent_80bit(my_double);
	if (decimal_exp < -4 || ctx->precision <= decimal_exp)
		ft_print_g_exp_notation_80bit(ctx, my_double, decimal_exp);
	else
		ft_print_g_fixed_point_80bit(ctx, my_double, decimal_exp);
}
