/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:18 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_s(t_printf_ctx *ctx, char *s);
static	void	ft_print_null(t_printf_ctx *ctx);

void	ft_conv_s(va_list *ap, t_printf_ctx *ctx)
{
	char	*s;

	if (!ft_strcmp(ctx->length, "l"))
	{
		ft_conv_ls(ap, ctx);
		return ;
	}
	s = va_arg(*ap, char *);
	if (!s)
	{
		ft_print_null(ctx);
		return ;
	}
	ft_print_s(ctx, s);
}

static	void	ft_print_s(t_printf_ctx *ctx, char *s)
{
	size_t	len;

	if (ctx->has_prec)
		len = ft_strnlen(s, ctx->precision);
	else
		len = ft_strlen(s);
	if (!ctx->width_flags || ctx->width_flags == '0')
		ft_print_space_width(ctx, len);
	ft_xprint_strn(ctx, s, len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static	void	ft_print_null(t_printf_ctx *ctx)
{
	char	*s;
	size_t	len;

	s = "(null)";
	len = ft_strlen(s);
	if (ctx->has_prec && len > (size_t)ctx->precision)
		len = 0;
	if (!ctx->width_flags || ctx->width_flags == '0')
		ft_print_space_width(ctx, len);
	ft_xprint_strn(ctx, s, len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
