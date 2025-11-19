/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprint_format_darwin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:17:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 22:56:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_plaintext(const char **format, t_printf_ctx *ctx);
static void	ft_print_error_format(const char **format, t_printf_ctx *ctx);

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
				ft_print_error_format(&format, ctx);
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

static void	ft_print_error_format(
				const char **format, t_printf_ctx *ctx)
{
	if (**format == '\0')
		return ;
	if (!ctx->width_flags)
		ft_print_space_width(ctx, 1);
	else if (ctx->width_flags == '0')
		ft_print_zero_width(ctx, 1);
	ft_xprint_char(ctx, **format);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, 1);
	(*format)++;
}
