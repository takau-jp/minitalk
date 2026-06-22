/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:42:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 12:41:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "../print_conversion_internal.h"

static void	print_conv_x(t_ctx *ctx, t_conv *conv, uintmax_t num);

void	pf_conv_x(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintmax_t	num;

	if (!conv->has_prec)
		conv->precision = 1;
	if (conv->length == LENGTH_HH)
		num = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else if (conv->length == LENGTH_H)
		num = (uintmax_t)(unsigned short int)va_arg(*ap, unsigned int);
	else if (conv->length == LENGTH_LOWER_L)
		num = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (conv->length == LENGTH_LOWER_LL)
		num = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (conv->length == LENGTH_J)
		num = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (conv->length == LENGTH_Z)
		num = (uintmax_t)va_arg(*ap, size_t);
	else if (conv->length == LENGTH_T)
		num = (uintmax_t)va_arg(*ap, size_t);
	else
		num = (uintmax_t)va_arg(*ap, unsigned int);
	print_conv_x(ctx, conv, num);
}

static void	print_conv_x(t_ctx *ctx, t_conv *conv, uintmax_t num)
{
	size_t		len;
	size_t		padding;

	len = pf_get_digits_base(num, 16);
	if (num == 0 && conv->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (conv->hash_flag == '#' && num != 0)
		len += ft_strlen("0x");
	if (conv->width_flags == '\0'
		|| (conv->width_flags == '0' && conv->has_prec))
		pf_print_space_width(ctx, conv, len + padding);
	if (conv->hash_flag == '#' && num != 0)
		pf_print_hexa_preffix(ctx, conv);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (conv->identifier == 'x' && !(num == 0 && conv->precision == 0))
		pf_print_nbr_base(ctx, num, "0123456789abcdef", 16);
	else if (conv->identifier == 'X' && !(num == 0 && conv->precision == 0))
		pf_print_nbr_base(ctx, num, "0123456789ABCDEF", 16);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}
