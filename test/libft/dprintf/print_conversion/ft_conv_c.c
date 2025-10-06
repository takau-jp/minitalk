/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:00:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_conv_c(va_list *ap, t_dprintf_ctx *ctx)
{
	int	c;

	if (!ft_strcmp(ctx->length, "l"))
	{
		ft_conv_lc(ap, ctx);
		return ;
	}
	c = va_arg(*ap, int);
	if (!ctx->width_flags || ctx->width_flags == '0')
		ft_print_space_width(ctx, 1);
	ft_dprint_char(ctx, c);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, 1);
}
