/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_g_exp_notation_80bit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:02:03 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:05:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int		ft_get_printable_precision_exp_notation(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static size_t	ft_get_length_g_exp_notation(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static void		ft_print_g_exp_notation_non_negative_exp(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static void		ft_print_g_exp_notation_negative_exp(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);

void	ft_print_g_exp_notation_80bit(
			t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	size_t	len;

	if (!ctx->hash_flag)
	{
		ctx->precision = ft_get_printable_precision_exp_notation(ctx,
				my_double, decimal_exp);
	}
	len = ft_get_length_g_exp_notation(ctx, my_double, decimal_exp);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	ft_print_sign(ctx, my_double->sign);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	if (decimal_exp >= 0)
		ft_print_g_exp_notation_non_negative_exp(ctx, my_double, decimal_exp);
	else
		ft_print_g_exp_notation_negative_exp(ctx, my_double, decimal_exp);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static int	ft_get_printable_precision_exp_notation(
				t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;
	int	precision;
	int	printable_prec;

	precision = 0;
	printable_prec = 0;
	if (decimal_exp > 0)
	{
		i = PF_LDBL_INT - (decimal_exp + 1);
		while (precision < ctx->precision && i < PF_LDBL_INT)
		{
			precision++;
			if (my_double->decimal_int[i++] != 0)
				printable_prec = precision;
		}
		i = 0;
	}
	else
		i = -(decimal_exp + 1);
	while (precision++ < ctx->precision && i < PF_LDBL_FRAC)
	{
		if (my_double->decimal_frac[i++] != 0)
			printable_prec = precision;
	}
	return (printable_prec);
}

static	size_t	ft_get_length_g_exp_notation(
					t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	size_t	len;
	size_t	exponent_digits;

	len = 0;
	if (my_double->sign || (my_double->sign == 0 && ctx->sign_flags))
		len++;
	len += ctx->precision;
	if (ctx->precision != 1 || ctx->hash_flag)
		len += 1;
	exponent_digits = 0;
	while (decimal_exp)
	{
		exponent_digits++;
		decimal_exp /= 10;
	}
	if (exponent_digits < 2)
		exponent_digits = 2;
	len += 2 + exponent_digits;
	return (len);
}

static void	ft_print_g_exp_notation_non_negative_exp(
				t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;
	int	precision;

	i = 0;
	while (i < PF_LDBL_INT && my_double->decimal_int[i] == 0)
		i++;
	ft_dprint_char(ctx, my_double->decimal_int[i++] + '0');
	if (ctx->precision != 1 || ctx->hash_flag)
		ft_dprint_char(ctx, '.');
	precision = ctx->precision - 1;
	while (precision && i < PF_LDBL_INT)
	{
		ft_dprint_char(ctx, my_double->decimal_int[i++] + '0');
		precision--;
	}
	i = 0;
	while (precision && i < PF_LDBL_FRAC)
	{
		ft_dprint_char(ctx, my_double->decimal_frac[i++] + '0');
		precision--;
	}
	while (precision-- && ctx->hash_flag)
		ft_dprint_char(ctx, '0');
	ft_print_exponent(ctx, decimal_exp);
}

static void	ft_print_g_exp_notation_negative_exp(
				t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;
	int	precision;

	i = 0;
	while (i < PF_LDBL_FRAC - 1 && my_double->decimal_frac[i] == 0)
		i++;
	ft_dprint_char(ctx, my_double->decimal_frac[i++] + '0');
	if (ctx->precision != 1 || ctx->hash_flag)
		ft_dprint_char(ctx, '.');
	precision = ctx->precision - 1;
	while (precision && i < PF_LDBL_FRAC)
	{
		ft_dprint_char(ctx, my_double->decimal_frac[i++] + '0');
		precision--;
	}
	while (precision-- && ctx->hash_flag)
		ft_dprint_char(ctx, '0');
	ft_print_exponent(ctx, decimal_exp);
}
