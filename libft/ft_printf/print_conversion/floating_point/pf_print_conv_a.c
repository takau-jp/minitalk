/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conv_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:40:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 16:49:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "./floating_point_internal.h"

static int		get_printable_precision_hex(t_pf_float *fp);
static size_t	get_length_float_hex(t_conv *conv, t_pf_float *fp);
static void		print_float_hex(t_ctx *ctx, t_conv *conv, t_pf_float *fp);

void	pf_print_conv_a(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	size_t	len;

	if (!conv->has_prec)
		conv->precision = get_printable_precision_hex(fp);
	len = get_length_float_hex(conv, fp);
	if (conv->width_flags == '\0')
		pf_print_space_width(ctx, conv, len);
	pf_print_sign(ctx, conv, fp->sign);
	pf_print_hexa_preffix(ctx, conv);
	if (conv->width_flags == '0')
		pf_print_zero_width(ctx, conv, len);
	print_float_hex(ctx, conv, fp);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}

static int	get_printable_precision_hex(t_pf_float *fp)
{
	int	i;
	int	printable_prec;

	i = 0;
	printable_prec = 0;
	while (i < fp->buf_frac_size)
	{
		if (fp->radix_point[i++] != 0)
			printable_prec = i;
	}
	return (printable_prec);
}

static size_t	get_length_float_hex(t_conv *conv, t_pf_float *fp)
{
	size_t	len;
	int		exp;
	size_t	exponent_digits;

	len = 0;
	if (fp->sign || (fp->sign == 0 && conv->sign_flags != '\0'))
		len += ft_strlen("-");
	len += ft_strlen("0x") + 1;
	if (!(conv->precision == 0 && conv->hash_flag != '#'))
		len += ft_strlen(".");
	len += conv->precision;
	exp = fp->exponent;
	exponent_digits = 0;
	while (exp != 0)
	{
		exponent_digits++;
		exp /= 10;
	}
	if (exponent_digits == 0)
		exponent_digits = 1;
	len += ft_strlen("p+") + exponent_digits;
	return (len);
}

static void	print_float_hex(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	int	i;

	pf_print_char(ctx, fp->print_buf[0] + '0');
	if (conv->precision > 0 || conv->hash_flag == '#')
		pf_print_char(ctx, '.');
	i = 0;
	while (conv->precision > 0 && i < fp->buf_frac_size)
	{
		if (conv->identifier == 'a')
			pf_print_char(ctx, "0123456789abcdef"[fp->radix_point[i++]]);
		else
			pf_print_char(ctx, "0123456789ABCDEF"[fp->radix_point[i++]]);
		conv->precision--;
	}
	while (conv->precision > 0)
	{
		pf_print_char(ctx, '0');
		conv->precision--;
	}
	pf_print_binary_exponent(ctx, conv, fp->exponent);
}
