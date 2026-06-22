/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conv_g_exp_notation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:54:23 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:32:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "./floating_point_internal.h"

static int		get_printable_precision_exp_notation(t_conv *conv,
					t_pf_float *fp, int decimal_exp);
static size_t	get_length_g_exp_notation(t_conv *conv,
					t_pf_float *fp, int decimal_exp);
static void		print_exp_notation(t_ctx *ctx, t_conv *conv,
					t_pf_float *fp, int decimal_exp);

void	pf_print_conv_g_exp_notation(
			t_ctx *ctx, t_conv *conv, t_pf_float *fp, int decimal_exp)
{
	size_t	len;

	if (conv->hash_flag != '#')
	{
		conv->precision = get_printable_precision_exp_notation(conv,
				fp, decimal_exp);
	}
	len = get_length_g_exp_notation(conv, fp, decimal_exp);
	if (conv->width_flags == '\0')
		pf_print_space_width(ctx, conv, len);
	pf_print_sign(ctx, conv, fp->sign);
	if (conv->width_flags == '0')
		pf_print_zero_width(ctx, conv, len);
	print_exp_notation(ctx, conv, fp, decimal_exp);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}

static int	get_printable_precision_exp_notation(
				t_conv *conv, t_pf_float *fp, int decimal_exp)
{
	int	printable_prec;
	int	precision;
	int	i;

	printable_prec = 0;
	precision = 0;
	i = -1 - decimal_exp;
	while (precision < conv->precision && i < fp->buf_frac_size)
	{
		precision++;
		if (fp->radix_point[i] != 0)
			printable_prec = precision;
		i++;
	}
	return (printable_prec);
}

static	size_t	get_length_g_exp_notation(
					t_conv *conv, t_pf_float *fp, int decimal_exp)
{
	size_t	len;
	size_t	exponent_digits;

	len = 0;
	if (fp->sign || (fp->sign == 0 && conv->sign_flags != '\0'))
		len += ft_strlen("-");
	len += conv->precision;
	if (conv->precision != 1 || conv->hash_flag == '#')
		len += ft_strlen(".");
	exponent_digits = 0;
	while (decimal_exp != 0)
	{
		exponent_digits++;
		decimal_exp /= 10;
	}
	if (exponent_digits < 2)
		exponent_digits = 2;
	len += ft_strlen("e+") + exponent_digits;
	return (len);
}

static void	print_exp_notation(
	t_ctx *ctx, t_conv *conv, t_pf_float *fp, int decimal_exp)
{
	int	i;

	i = fp->buf_int_size - 1 - decimal_exp;
	pf_print_char(ctx, fp->print_buf[i++] + '0');
	conv->precision--;
	if (conv->precision > 0 || conv->hash_flag == '#')
		pf_print_char(ctx, '.');
	while (conv->precision > 0 && i < fp->buf_size)
	{
		pf_print_char(ctx, fp->print_buf[i++] + '0');
		conv->precision--;
	}
	while (conv->precision > 0)
	{
		pf_print_char(ctx, '0');
		conv->precision--;
	}
	pf_print_decimal_exponent(ctx, conv, decimal_exp);
}
