/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_xprintf_darwin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:17:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:39:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/read_conversion.h"
#include "ft_printf/print_conversion.h"
#include "ft_printf/print_utils.h"

static void	print_plaintext(const char **format, t_ctx *ctx);
static void	print_error_format(const char **format, t_ctx *ctx, t_conv *conv);

void	pf_xprintf(t_ctx *ctx, va_list *ap, const char *format)
{
	t_conv	conv;

	while (!ctx->has_error && *format != '\0')
	{
		if (*format != '%')
			print_plaintext(&format, ctx);
		else
		{
			ft_bzero(&conv, sizeof(t_conv));
			if (!pf_read_conversion(ap, &format, ctx, &conv))
			{
				if (ctx->has_error)
					return ;
				print_error_format(&format, ctx, &conv);
				continue ;
			}
			pf_print_conversion(ap, ctx, &conv);
		}
	}
}

static void	print_plaintext(const char **format, t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while ((*format)[i] != '\0' && (*format)[i] != '%')
		i++;
	pf_print_strn(ctx, (char *)*format, i);
	*format += i;
}

static void	print_error_format(const char **format, t_ctx *ctx, t_conv *conv)
{
	if (**format == '\0')
		return ;
	if (conv->width_flags == '\0')
		pf_print_space_width(ctx, conv, 1);
	else if (conv->width_flags == '0')
		pf_print_zero_width(ctx, conv, 1);
	pf_print_char(ctx, **format);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, 1);
	(*format)++;
}
