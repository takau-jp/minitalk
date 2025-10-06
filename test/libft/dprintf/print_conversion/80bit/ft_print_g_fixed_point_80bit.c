/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_g_fixed_point_80bit.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:55:57 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:04:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int		ft_get_printable_precision_fixed_point(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static size_t	ft_get_length_g_fixed_point(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static void		ft_print_g_fixed_point_non_negative_exp(t_dprintf_ctx *ctx,
					t_my_double *my_double, int decimal_exp);
static void		ft_print_g_fixed_point_negative_exp(
					t_dprintf_ctx *ctx, t_my_double *my_double);

void	ft_print_g_fixed_point_80bit(
			t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	size_t		len;

	if (!ctx->hash_flag)
	{
		ctx->precision = ft_get_printable_precision_fixed_point(ctx,
				my_double, decimal_exp);
	}
	len = ft_get_length_g_fixed_point(ctx, my_double, decimal_exp);
	if (!ctx->width_flags)
		ft_print_space_width(ctx, len);
	ft_print_sign(ctx, my_double->sign);
	if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, len);
	if (decimal_exp >= 0)
		ft_print_g_fixed_point_non_negative_exp(ctx, my_double, decimal_exp);
	else
		ft_print_g_fixed_point_negative_exp(ctx, my_double);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static int	ft_get_printable_precision_fixed_point(
				t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;
	int	precision;
	int	printable_prec;

	printable_prec = 0;
	if (decimal_exp > 0)
	{
		printable_prec += decimal_exp + 1;
		precision = printable_prec;
		i = 0;
	}
	else
	{
		precision = 0;
		i = -(decimal_exp + 1);
	}
	while (precision < ctx->precision && i < PF_LDBL_FRAC)
	{
		precision++;
		if (my_double->decimal_frac[i++] != 0)
			printable_prec = precision;
	}
	return (printable_prec);
}

static size_t	ft_get_length_g_fixed_point(
					t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	size_t	len;

	len = 0;
	if (my_double->sign || (my_double->sign == 0 && ctx->sign_flags))
		len++;
	len += ctx->precision;
	if (ctx->precision > decimal_exp + 1 || ctx->hash_flag)
		len += 1;
	return (len);
}

static void	ft_print_g_fixed_point_non_negative_exp(
				t_dprintf_ctx *ctx, t_my_double *my_double, int decimal_exp)
{
	int	i;

	i = PF_LDBL_INT - (decimal_exp + 1);
	while (i < PF_LDBL_INT)
	{
		ft_dprint_char(ctx, my_double->decimal_int[i] + '0');
		i++;
		ctx->precision--;
	}
	if (ctx->precision > 0 || ctx->hash_flag)
		ft_dprint_char(ctx, '.');
	if (ctx->precision <= 0)
		return ;
	i = 0;
	while (ctx->precision && i < PF_LDBL_FRAC)
	{
		ft_dprint_char(ctx, my_double->decimal_frac[i] + '0');
		i++;
		ctx->precision--;
	}
	while (ctx->precision && ctx->hash_flag)
	{
		ft_dprint_char(ctx, '0');
		ctx->precision--;
	}
}

static void	ft_print_g_fixed_point_negative_exp(
				t_dprintf_ctx *ctx, t_my_double *my_double)
{
	int	i;

	ft_dprint_char(ctx, '0');
	ft_dprint_char(ctx, '.');
	i = 0;
	while (i < PF_LDBL_FRAC && my_double->decimal_frac[i] == 0)
	{
		ft_dprint_char(ctx, '0');
		i++;
	}
	while (ctx->precision && i < PF_LDBL_FRAC)
	{
		ft_dprint_char(ctx, my_double->decimal_frac[i] + '0');
		i++;
		ctx->precision--;
	}
	while (ctx->precision && ctx->hash_flag)
	{
		ft_dprint_char(ctx, '0');
		ctx->precision--;
	}
}
