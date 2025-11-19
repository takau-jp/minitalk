/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_p(t_printf_ctx *ctx, uintptr_t pointer);
static size_t	ft_get_length_pointer(uintptr_t pointer);
static void		ft_print_pointer(t_printf_ctx *ctx, uintptr_t pointer);
static void		ft_print_p_null(t_printf_ctx *ctx);

void	ft_conv_p(va_list *ap, t_printf_ctx *ctx)
{
	uintptr_t	pointer;

	pointer = (uintptr_t)va_arg(*ap, void *);
	if ((void *)pointer == NULL)
	{
		ft_print_p_null(ctx);
		return ;
	}
	ft_print_p(ctx, pointer);
}

static void	ft_print_p(t_printf_ctx *ctx, uintptr_t pointer)
{
	size_t		len;
	size_t		padding;

	len = ft_get_length_pointer(pointer);
	padding = 0;
	if (len < (size_t)ctx->precision)
		padding = ctx->precision - len;
	if (ctx->sign_flags)
		len += ft_strlen("+");
	len += ft_strlen("0x");
	if (!ctx->width_flags || (ctx->width_flags == '0' && ctx->has_prec))
		ft_print_space_width(ctx, len + padding);
	ft_print_sign(ctx, false);
	ft_xprint_strn(ctx, "0x", 2);
	if (ctx->width_flags == '0' && !ctx->has_prec)
		ft_print_zero_width(ctx, len + padding);
	ft_print_padding(ctx, padding);
	ft_print_pointer(ctx, pointer);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len + padding);
}

static size_t	ft_get_length_pointer(uintptr_t pointer)
{
	size_t	digits;

	digits = 0;
	while (pointer)
	{
		pointer /= 16;
		digits++;
	}
	return (digits);
}

static void	ft_print_pointer(t_printf_ctx *ctx, uintptr_t pointer)
{
	if (pointer >= 16)
		ft_print_pointer(ctx, pointer / 16);
	ft_xprint_char(ctx, "0123456789abcdef"[pointer % 16]);
}

static void	ft_print_p_null(t_printf_ctx *ctx)
{
	size_t		len;

	len = ft_strlen("(nil)");
	if (ctx->width_flags != '-')
		ft_print_space_width(ctx, len);
	ft_xprint_strn(ctx, "(nil)", len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
