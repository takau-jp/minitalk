/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:52:49 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:35:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_print_conversion(va_list *ap, t_dprintf_ctx *ctx)
{
	if (ctx->conv == 'c')
		ft_conv_c(ap, ctx);
	else if (ctx->conv == 's')
		ft_conv_s(ap, ctx);
	else if (ctx->conv == 'd' || ctx->conv == 'i')
		ft_conv_d_i(ap, ctx);
	else if (ctx->conv == 'u')
		ft_conv_u(ap, ctx);
	else if (ctx->conv == 'o')
		ft_conv_o(ap, ctx);
	else if (ft_strchr("xX", ctx->conv))
		ft_conv_x(ap, ctx);
	else if (ctx->conv == 'p')
		ft_conv_p(ap, ctx);
	else if (ft_strchr("fFeEgG", ctx->conv))
		ft_conv_f_e_g(ap, ctx);
	else if (ft_strchr("aA", ctx->conv))
		ft_conv_a(ap, ctx);
	else if (ctx->conv == '%')
		ft_conv_percent(ctx);
	else if (ctx->conv == 'n')
		ft_conv_n(ap, ctx);
}
