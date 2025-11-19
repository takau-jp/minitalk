/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f_binary64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:51:36 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_f(t_printf_ctx *ctx, t_my_double *my_double);
static size_t	ft_get_length_fixed_point(
					t_printf_ctx *ctx, t_my_double *my_double);
static void		ft_print_fixed_point(
					t_printf_ctx *ctx, t_my_double *my_double);

void	ft_conv_f_binary64(va_list *ap, t_printf_ctx *ctx)
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
	ft_round_to_nearest_even_binary64(&my_double, ctx->precision);
	if (my_double.exponent == DBL_NAN_INF)
		ft_print_nan_inf_binary64(ctx, &my_double);
	else
		ft_print_f(ctx, &my_double);
	ft_free_my_double(&my_double);
}

static void	ft_print_f(t_printf_ctx *ctx, t_my_double *my_double)
{
	size_t		len;

	len = ft_get_length_fixed_point(ctx, my_double);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	ft_print_sign(ctx, my_double->sign);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	ft_print_fixed_point(ctx, my_double);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static size_t	ft_get_length_fixed_point(
					t_printf_ctx *ctx, t_my_double *my_double)
{
	size_t	len;
	int		i;

	len = 0;
	if (my_double->sign || (my_double->sign == 0 && ctx->sign_flags))
		len += ft_strlen("-");
	if (my_double->int_binary == 0)
		len += ft_strlen("0");
	else
	{
		i = 0;
		while (i < PF_DBL_INT)
		{
			if (my_double->decimal_int[i] != 0)
			{
				len += PF_DBL_INT - i;
				break ;
			}
			i++;
		}
	}
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		len += ft_strlen(".");
	len += ctx->precision;
	return (len);
}

static void	ft_print_fixed_point(
				t_printf_ctx *ctx, t_my_double *my_double)
{
	int	i;

	i = 0;
	while (i < PF_DBL_INT - 1 && my_double->decimal_int[i] == 0)
		i++;
	while (i < PF_DBL_INT)
		ft_xprint_char(ctx, my_double->decimal_int[i++] + '0');
	if (!(ctx->precision == 0 && !ctx->hash_flag))
		ft_xprint_char(ctx, '.');
	i = 0;
	while (i < PF_DBL_FRAC && i < ctx->precision)
		ft_xprint_char(ctx, my_double->decimal_frac[i++] + '0');
	while (i++ < ctx->precision)
		ft_xprint_char(ctx, '0');
}
