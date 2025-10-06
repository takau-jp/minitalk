/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:50:56 by stanaka2          #+#    #+#             */
/*   Updated: 2025/05/27 20:25:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_dprint_format(int fd, va_list *ap, const char *format);
static void	ft_print_plaintext(const char **format, t_dprintf_ctx *ctx);
static void	ft_print_error_format(t_dprintf_ctx *ctx);
static void	ft_print_num(t_dprintf_ctx *ctx, int num);

int	ft_dprintf(int fd, const char *format, ...)
{
	int		res;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	res = ft_dprint_format(fd, &ap, format);
	va_end(ap);
	return (res);
}

static int	ft_dprint_format(int fd, va_list *ap, const char *format)
{
	t_dprintf_ctx	ctx;

	ctx.fd = fd;
	ctx.res = 0;
	while (!(ctx.res < 0) && *format)
	{
		if (*format != '%')
			ft_print_plaintext(&format, &ctx);
		else
		{
			ft_reset_conversion(&ctx);
			if (!ft_read_conversion(ap, &format, &ctx))
			{
				if (ctx.res < 0)
					return (-1);
				ft_print_error_format(&ctx);
				continue ;
			}
			ft_print_conversion(ap, &ctx);
		}
	}
	if (ctx.res < 0)
		return (-1);
	return (ctx.res);
}

static void	ft_print_plaintext(const char **format, t_dprintf_ctx *ctx)
{
	size_t	i;

	i = 0;
	while ((*format)[i] && (*format)[i] != '%')
		i++;
	ft_dprint_strn(ctx, (char *)*format, i);
	*format += i;
}

static void	ft_print_error_format(t_dprintf_ctx *ctx)
{
	ft_dprint_char(ctx, '%');
	if (ctx->hash_flag)
		ft_dprint_char(ctx, ctx->hash_flag);
	if (ctx->sign_flags)
		ft_dprint_char(ctx, ctx->sign_flags);
	if (ctx->width_flags)
		ft_dprint_char(ctx, ctx->width_flags);
	if (ctx->width > 0)
		ft_print_num(ctx, ctx->width);
	if (ctx->has_prec)
	{
		ft_dprint_char(ctx, '.');
		ft_print_num(ctx, ctx->precision);
	}
}

static void	ft_print_num(t_dprintf_ctx *ctx, int num)
{
	unsigned int	u_num;

	u_num = num;
	if (num < 0)
		u_num = -num;
	if (u_num >= 10)
		ft_print_num(ctx, u_num / 10);
	ft_dprint_char(ctx, "0123456789"[u_num % 10]);
}
