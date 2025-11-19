/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent_darwin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:40:06 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_percent(t_printf_ctx *ctx)
{
	if (!ctx->width_flags)
		ft_print_space_width(ctx, 1);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, 1);
	ft_xprint_char(ctx, '%');
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, 1);
}
