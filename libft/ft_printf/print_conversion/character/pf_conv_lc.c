/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:45:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "./character_internal.h"

void	pf_conv_lc(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	wint_t			wi;
	wint_t			wc;
	unsigned char	utf8[UTF8_SIZE];
	size_t			len;

	wi = va_arg(*ap, wint_t);
	wc = (wchar_t)wi;
	if (wi == WEOF || !pf_validate_codepoint(wc))
	{
		ctx->has_error = true;
		return ;
	}
	len = pf_calc_utf8_len(wc);
	pf_encode_utf8(wc, utf8);
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_utf8(ctx, utf8, len);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}
