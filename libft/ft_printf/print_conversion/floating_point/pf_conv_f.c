/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 20:59:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./floating_point_internal.h"

static void	process_conv_f(t_ctx *ctx, t_conv *conv, t_pf_float *fp);

void	pf_conv_f_binary64(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	double		num;
	t_pf_float	fp;

	if (conv->has_prec == false)
		conv->precision = 6;
	num = va_arg(*ap, double);
	if (!pf_float_init(&fp, BINARY64_SIZE, 10))
	{
		ctx->has_error = true;
		return ;
	}
	pf_decode_binary64(num, &fp);
	process_conv_f(ctx, conv, &fp);
	pf_float_destroy(&fp);
}

void	pf_conv_f_binary80(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	long double	num;
	t_pf_float	fp;

	if (conv->has_prec == false)
		conv->precision = 6;
	num = va_arg(*ap, long double);
	if (!pf_float_init(&fp, BINARY80_SIZE, 10))
	{
		ctx->has_error = true;
		return ;
	}
	pf_decode_binary80(num, &fp);
	process_conv_f(ctx, conv, &fp);
	pf_float_destroy(&fp);
}

static void	process_conv_f(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	if (fp->value_type == FLOAT_INF)
	{
		pf_print_inf(ctx, conv, fp);
		return ;
	}
	if (fp->value_type == FLOAT_NAN)
	{
		pf_print_nan(ctx, conv, fp);
		return ;
	}
	if (!pf_convert_to_decimal(fp))
	{
		ctx->has_error = true;
		return ;
	}
	pf_round_to_nearest_even(fp, conv->precision);
	pf_print_conv_f(ctx, conv, fp);
}
