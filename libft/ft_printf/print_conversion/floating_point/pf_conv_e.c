/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 00:13:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./floating_point_internal.h"

static void	process_conv_e(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
static int	normalize_rounding_precision(t_pf_float *fp, int precision);

void	pf_conv_e_binary64(va_list *ap, t_ctx *ctx, t_conv *conv)
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
	process_conv_e(ctx, conv, &fp);
	pf_float_destroy(&fp);
}

void	pf_conv_e_binary80(va_list *ap, t_ctx *ctx, t_conv *conv)
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
	process_conv_e(ctx, conv, &fp);
	pf_float_destroy(&fp);
}

static void	process_conv_e(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
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
	pf_round_to_nearest_even(\
		fp, normalize_rounding_precision(fp, conv->precision));
	pf_print_conv_e(ctx, conv, fp);
}

static int	normalize_rounding_precision(t_pf_float *fp, int precision)
{
	int	i;

	if (fp->value_type == FLOAT_ZERO)
		return (precision - 1);
	i = 0;
	if (fp->int_binary != 0)
	{
		while (i < fp->buf_int_size && fp->print_buf[i] == 0)
			i++;
		precision -= (fp->buf_int_size - i);
	}
	else
	{
		while (fp->radix_point[i] == 0)
			i++;
		precision += i;
	}
	return (precision + 1);
}
