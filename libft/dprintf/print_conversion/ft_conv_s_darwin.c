/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s_darwin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:28:39 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:01:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static	void	ft_print_s(t_dprintf_ctx *ctx, char *s);

void	ft_conv_s(va_list *ap, t_dprintf_ctx *ctx)
{
	char	*s;

	if (!ft_strcmp(ctx->length, "l"))
	{
		ft_conv_ls(ap, ctx);
		return ;
	}
	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	ft_print_s(ctx, s);
}

static	void	ft_print_s(t_dprintf_ctx *ctx, char *s)
{
	size_t	len;

	if (ctx->has_prec)
		len = ft_strnlen(s, ctx->precision);
	else
		len = ft_strlen(s);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	ft_dprint_strn(ctx, s, len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
