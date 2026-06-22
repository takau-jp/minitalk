/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:48:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 16:46:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/conversions/character.h"
#include "ft_printf/conversions/integer.h"
#include "ft_printf/conversions/floating_point.h"
#include "ft_printf/conversions/special.h"

static void	print_character_conversion(\
				va_list *ap, t_ctx *ctx, t_conv *conv);
static void	print_integer_conversion(\
				va_list *ap, t_ctx *ctx, t_conv *conv);
static void	print_float_conversion(va_list *ap, t_ctx *ctx, t_conv *conv);

void	pf_print_conversion(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	if (ft_strchr("cs", conv->identifier) != NULL)
		print_character_conversion(ap, ctx, conv);
	else if (ft_strchr("diuoxX", conv->identifier) != NULL)
		print_integer_conversion(ap, ctx, conv);
	else if (ft_strchr("fFeEgGaA", conv->identifier) != NULL)
		print_float_conversion(ap, ctx, conv);
	else if (conv->identifier == 'p')
		pf_conv_p(ap, ctx, conv);
	else if (conv->identifier == '%')
		pf_conv_percent(ctx, conv);
	else if (conv->identifier == 'n')
		pf_conv_n(ap, ctx, conv);
}

static void	print_character_conversion(
	va_list *ap, t_ctx *ctx, t_conv *conv)
{
	if (conv->length == LENGTH_LOWER_L)
	{
		if (conv->identifier == 'c')
			pf_conv_lc(ap, ctx, conv);
		else if (conv->identifier == 's')
			pf_conv_ls(ap, ctx, conv);
	}
	else
	{
		if (conv->identifier == 'c')
			pf_conv_c(ap, ctx, conv);
		else if (conv->identifier == 's')
			pf_conv_s(ap, ctx, conv);
	}
}

static void	print_integer_conversion(
	va_list *ap, t_ctx *ctx, t_conv *conv)
{
	if (conv->identifier == 'd' || conv->identifier == 'i')
		pf_conv_d_i(ap, ctx, conv);
	else if (conv->identifier == 'u')
		pf_conv_u(ap, ctx, conv);
	else if (conv->identifier == 'o')
		pf_conv_o(ap, ctx, conv);
	else if (conv->identifier == 'x' || conv->identifier == 'X')
		pf_conv_x(ap, ctx, conv);
}

static void	print_float_conversion(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	if (conv->length == LENGTH_UPPER_L)
	{
		if (conv->identifier == 'f' || conv->identifier == 'F')
			pf_conv_f_binary80(ap, ctx, conv);
		else if (conv->identifier == 'e' || conv->identifier == 'E')
			pf_conv_e_binary80(ap, ctx, conv);
		else if (conv->identifier == 'g' || conv->identifier == 'G')
			pf_conv_g_binary80(ap, ctx, conv);
		else if (conv->identifier == 'a' || conv->identifier == 'A')
			pf_conv_a_binary80(ap, ctx, conv);
	}
	else
	{
		if (conv->identifier == 'f' || conv->identifier == 'F')
			pf_conv_f_binary64(ap, ctx, conv);
		else if (conv->identifier == 'e' || conv->identifier == 'E')
			pf_conv_e_binary64(ap, ctx, conv);
		else if (conv->identifier == 'g' || conv->identifier == 'G')
			pf_conv_g_binary64(ap, ctx, conv);
		else if (conv->identifier == 'a' || conv->identifier == 'A')
			pf_conv_a_binary64(ap, ctx, conv);
	}
}
