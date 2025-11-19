/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f_e_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_f_e_g_longdouble(va_list *ap, t_printf_ctx *ctx);

void	ft_conv_f_e_g(va_list *ap, t_printf_ctx *ctx)
{
	if (!ft_strcmp(ctx->length, "L"))
	{
		if (__LDBL_MANT_DIG__ == 64)
		{
			ft_conv_f_e_g_longdouble(ap, ctx);
			return ;
		}
	}
	if (ctx->conv == 'f' || ctx->conv == 'F')
		ft_conv_f_binary64(ap, ctx);
	else if (ctx->conv == 'e' || ctx->conv == 'E')
		ft_conv_e_binary64(ap, ctx);
	else if (ctx->conv == 'g' || ctx->conv == 'G')
		ft_conv_g_binary64(ap, ctx);
}

static void	ft_conv_f_e_g_longdouble(va_list *ap, t_printf_ctx *ctx)
{
	if (__LDBL_MANT_DIG__ == 64)
	{
		if (ctx->conv == 'f' || ctx->conv == 'F')
			ft_conv_f_80bit(ap, ctx);
		else if (ctx->conv == 'e' || ctx->conv == 'E')
			ft_conv_e_80bit(ap, ctx);
		else if (ctx->conv == 'g' || ctx->conv == 'G')
			ft_conv_g_80bit(ap, ctx);
	}
}
