/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:45:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 12:41:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "../print_conversion_internal.h"

static void	print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer);
static void	print_nullptr(t_ctx *ctx, t_conv *conv);

void	pf_conv_p(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintptr_t	pointer;

	pointer = (uintptr_t)va_arg(*ap, void *);
	if ((void *)pointer == NULL)
	{
		print_nullptr(ctx, conv);
		return ;
	}
	print_conv_p(ctx, conv, pointer);
}

static void	print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer)
{
	size_t		len;
	size_t		padding;

	len = pf_get_digits_base((uintmax_t)pointer, 16);
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (conv->sign_flags != '\0')
		len += ft_strlen("+");
	len += ft_strlen("0x");
	if (conv->width_flags == '\0' \
		|| (conv->width_flags == '0' && conv->has_prec))
	{
		pf_print_space_width(ctx, conv, len + padding);
	}
	pf_print_sign(ctx, conv, false);
	pf_print_hexa_preffix(ctx, conv);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	pf_print_nbr_base(ctx, (uintmax_t)pointer, "0123456789abcdef", 16);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static void	print_nullptr(t_ctx *ctx, t_conv *conv)
{
	size_t		len;

	len = ft_strlen("(nil)");
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_strn(ctx, "(nil)", len);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}
