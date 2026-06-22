/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_p_darwin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:30:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 12:42:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "../print_conversion_internal.h"

static void	print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer);

void	pf_conv_p(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintptr_t	pointer;

	pointer = (uintptr_t)va_arg(*ap, void *);
	print_conv_p(ctx, conv, pointer);
}

static void	print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer)
{
	size_t	len;
	size_t	padding;

	len = pf_get_digits_base((uintmax_t)pointer, 16);
	if ((void *)pointer == NULL && conv->has_prec && conv->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	len += ft_strlen("0x");
	if (conv->width_flags == '\0' \
		|| (conv->width_flags == '0' && conv->has_prec))
	{
		pf_print_space_width(ctx, conv, len + padding);
	}
	pf_print_hexa_preffix(ctx, conv);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (!((void *)pointer == NULL && conv->has_prec && conv->precision == 0))
		pf_print_nbr_base(ctx, (uintmax_t)pointer, "0123456789abcdef", 16);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}
