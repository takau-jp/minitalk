/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lc_darwin_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:20:34 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:32:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_conv_lc(va_list *ap, t_dprintf_ctx *ctx)
{
	wint_t			wc;
	unsigned char	utf8[5];
	size_t			len;

	wc = va_arg(*ap, wint_t);
	ft_encode_wchar_to_utf8(utf8, wc);
	len = ft_strlen((char *)utf8);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	ft_print_utf8(ctx, utf8, len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
