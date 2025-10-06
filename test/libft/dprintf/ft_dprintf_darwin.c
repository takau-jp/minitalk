/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_darwin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:38:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 18:58:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_dprint_format(int fd, va_list *ap, const char *format);
static void	ft_print_plaintext(const char **format, t_dprintf_ctx *ctx);
static void	ft_print_error_format(const char **format, t_dprintf_ctx *ctx);

int	ft_dprintf(int fd, const char *format, ...)
{
	int		res;
	va_list	ap;

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
				ft_print_error_format(&format, &ctx);
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

static void	ft_print_error_format(
				const char **format, t_dprintf_ctx *ctx)
{
	if (**format == '\0')
		return ;
	if (!ctx->width_flags)
		ft_print_space_width(ctx, 1);
	else if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, 1);
	ft_dprint_char(ctx, **format);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, 1);
	(*format)++;
}
