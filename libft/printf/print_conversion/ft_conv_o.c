/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:50:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_o(t_printf_ctx *ctx, uintmax_t num);
static size_t	ft_get_digits_uintmax_octal(uintmax_t num);
static void		ft_print_octal(t_printf_ctx *ctx, uintmax_t num);

void	ft_conv_o(va_list *ap, t_printf_ctx *ctx)
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
	ft_print_o(ctx, num);
}

static void	ft_print_o(t_printf_ctx *ctx, uintmax_t num)
{
	size_t		len;
	size_t		padding;

	len = ft_get_digits_uintmax_octal(num);
	if (num == 0 && ctx->precision == 0)
		len = 0;
	padding = 0;
	if (ctx->hash_flag && (num != 0) && (size_t)ctx->precision <= len)
		ctx->precision = len + 1;
	else if (ctx->hash_flag && num == 0 && ctx->precision == 0)
		padding = 1;
	if (len < (size_t)ctx->precision)
		padding = ctx->precision - len;
	if (!ctx->width_flags || (ctx->width_flags == '0' && ctx->has_prec))
		ft_print_space_width(ctx, len + padding);
	else if (ctx->width_flags == '0' && !ctx->has_prec)
		ft_print_zero_width(ctx, len + padding);
	ft_print_padding(ctx, padding);
	if (!(num == 0 && ctx->precision == 0))
		ft_print_octal(ctx, num);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len + padding);
}

static size_t	ft_get_digits_uintmax_octal(uintmax_t num)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num)
	{
		num /= 8;
		digits++;
	}
	return (digits);
}

static void	ft_print_octal(t_printf_ctx *ctx, uintmax_t num)
{
	if (num >= 8)
		ft_print_octal(ctx, num / 8);
	ft_xprint_char(ctx, "01234567"[num % 8]);
}
