/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:21 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:01:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void		ft_print_u(t_dprintf_ctx *ctx, uintmax_t num);
static size_t	ft_get_digits_uintmax(uintmax_t num);
static void		ft_print_unsigned(t_dprintf_ctx *ctx, uintmax_t num);

void	ft_conv_u(va_list *ap, t_dprintf_ctx *ctx)
{
	uintmax_t	num;

	if (!ctx->has_prec)
		ctx->precision = 1;
	if (!ft_strcmp(ctx->length, "hh"))
		num = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(ctx->length, "h"))
		num = (uintmax_t)(unsigned short int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(ctx->length, "l"))
		num = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (!ft_strcmp(ctx->length, "ll"))
		num = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (!ft_strcmp(ctx->length, "j"))
		num = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(ctx->length, "z"))
		num = (uintmax_t)va_arg(*ap, size_t);
	else if (!ft_strcmp(ctx->length, "t"))
		num = (uintmax_t)va_arg(*ap, size_t);
	else
		num = (uintmax_t)va_arg(*ap, unsigned int);
	ft_print_u(ctx, num);
}

static void	ft_print_u(t_dprintf_ctx *ctx, uintmax_t num)
{
	size_t		len;
	size_t		padding;

	len = ft_get_digits_uintmax(num);
	if (num == 0 && ctx->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)ctx->precision)
		padding = ctx->precision - len;
	if (!ctx->width_flags
		|| (ctx->width_flags == '0' && ctx->has_prec))
		ft_print_space_width(ctx, len + padding);
	else if (ctx->width_flags == '0' && !ctx->has_prec)
		ft_print_zero_width(ctx, len + padding);
	ft_print_padding(ctx, padding);
	if (!(num == 0 && ctx->precision == 0))
		ft_print_unsigned(ctx, num);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len + padding);
}

static size_t	ft_get_digits_uintmax(uintmax_t num)
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

static void	ft_print_unsigned(t_dprintf_ctx *ctx, uintmax_t num)
{
	if (num >= 10)
		ft_print_unsigned(ctx, num / 10);
	ft_dprint_char(ctx, "0123456789"[num % 10]);
}
