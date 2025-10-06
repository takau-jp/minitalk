/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:00:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void		ft_print_d_i(t_dprintf_ctx *ctx, intmax_t num);
static size_t	ft_get_digits_intmax(intmax_t num);
static void		ft_print_integer(t_dprintf_ctx *ctx, intmax_t num);

void	ft_conv_d_i(va_list *ap, t_dprintf_ctx *ctx)
{
	intmax_t	num;

	if (!ctx->has_prec)
		ctx->precision = 1;
	if (!ft_strcmp(ctx->length, "hh"))
		num = (intmax_t)(signed char)va_arg(*ap, int);
	else if (!ft_strcmp(ctx->length, "h"))
		num = (intmax_t)(short int)va_arg(*ap, int);
	else if (!ft_strcmp(ctx->length, "l"))
		num = (intmax_t)va_arg(*ap, long int);
	else if (!ft_strcmp(ctx->length, "ll"))
		num = (intmax_t)va_arg(*ap, long long int);
	else if (!ft_strcmp(ctx->length, "j"))
		num = (intmax_t)va_arg(*ap, intmax_t);
	else if (!ft_strcmp(ctx->length, "z"))
		num = (intmax_t)va_arg(*ap, ssize_t);
	else if (!ft_strcmp(ctx->length, "t"))
		num = (intmax_t)va_arg(*ap, ptrdiff_t);
	else
		num = (intmax_t)va_arg(*ap, int);
	ft_print_d_i(ctx, num);
}

static void	ft_print_d_i(t_dprintf_ctx *ctx, intmax_t num)
{
	size_t		len;
	size_t		padding;

	len = ft_get_digits_intmax(num);
	if (num == 0 && ctx->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)ctx->precision)
		padding = ctx->precision - len;
	if (num < 0 || (0 <= num && ctx->sign_flags))
		len += ft_strlen("-");
	if (!ctx->width_flags
		|| (ctx->width_flags == '0' && ctx->has_prec))
		ft_print_space_width(ctx, len + padding);
	ft_print_sign(ctx, num < 0);
	if (ctx->width_flags == '0' && !ctx->has_prec)
		ft_print_zero_width(ctx, len + padding);
	ft_print_padding(ctx, padding);
	if (!(num == 0 && ctx->precision == 0))
		ft_print_integer(ctx, num);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len + padding);
}

static size_t	ft_get_digits_intmax(intmax_t num)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_print_integer(t_dprintf_ctx *ctx, intmax_t num)
{
	uintmax_t	u_num;

	u_num = num;
	if (num < 0)
		u_num = -num;
	if (u_num >= 10)
		ft_print_integer(ctx, u_num / 10);
	ft_dprint_char(ctx, "0123456789"[u_num % 10]);
}
