/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprint_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:17:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 23:01:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_plaintext(const char **format, t_printf_ctx *ctx);
static void	ft_print_error_format(t_printf_ctx *ctx);
static void	ft_print_num(t_printf_ctx *ctx, int num);

void	ft_xprint_format(t_printf_ctx *ctx, va_list *ap, const char *format)
{
	while (!(ctx->res < 0) && *format)
	{
		if (*format != '%')
			ft_print_plaintext(&format, ctx);
		else
		{
			ft_reset_conversion(ctx);
			if (!ft_read_conversion(ap, &format, ctx))
			{
				if (ctx->res < 0)
					break ;
				ft_print_error_format(ctx);
				continue ;
			}
			ft_print_conversion(ap, ctx);
		}
	}
}

static void	ft_print_plaintext(const char **format, t_printf_ctx *ctx)
{
	size_t	i;

	i = 0;
	while ((*format)[i] && (*format)[i] != '%')
		i++;
	ft_xprint_strn(ctx, (char *)*format, i);
	*format += i;
}

static void	ft_print_error_format(t_printf_ctx *ctx)
{
	ft_xprint_char(ctx, '%');
	if (ctx->hash_flag)
		ft_xprint_char(ctx, ctx->hash_flag);
	if (ctx->sign_flags)
		ft_xprint_char(ctx, ctx->sign_flags);
	if (ctx->width_flags)
		ft_xprint_char(ctx, ctx->width_flags);
	if (ctx->width > 0)
		ft_print_num(ctx, ctx->width);
	if (ctx->has_prec)
	{
		ft_xprint_char(ctx, '.');
		ft_print_num(ctx, ctx->precision);
	}
}

static void	ft_print_num(t_printf_ctx *ctx, int num)
{
	unsigned int	u_num;

	u_num = num;
	if (num < 0)
		u_num = -num;
	if (u_num >= 10)
		ft_print_num(ctx, u_num / 10);
	ft_xprint_char(ctx, "0123456789"[u_num % 10]);
}
