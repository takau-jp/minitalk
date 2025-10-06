/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_g_binary64_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:51:42 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:30:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_conv_g_determine_format(
				t_dprintf_ctx *ctx, t_my_double *my_double);

void	ft_conv_g_binary64(va_list *ap, t_dprintf_ctx *ctx)
{
	double		num;
	t_my_double	my_double;

	if (ctx->has_prec == false)
		ctx->precision = 6;
	if (ctx->has_prec == true && ctx->precision == 0)
		ctx->precision = 1;
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
	if (my_double.exponent == DBL_NAN_INF)
		ft_print_nan_inf_binary64(ctx, &my_double);
	else
		ft_conv_g_determine_format(ctx, &my_double);
	ft_free_my_double(&my_double);
}

static void	ft_conv_g_determine_format(
				t_dprintf_ctx *ctx, t_my_double *my_double)
{
	int		decimal_exp;

	ft_round_to_nearest_even_exp_notation_binary64(my_double,
		ctx->precision - 1);
	decimal_exp = ft_get_decimal_exponent_binary64(my_double);
	if (decimal_exp < -4 || ctx->precision <= decimal_exp)
		ft_print_g_exp_notation_binary64(ctx, my_double, decimal_exp);
	else
		ft_print_g_fixed_point_binary64(ctx, my_double, decimal_exp);
}
