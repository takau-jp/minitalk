/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_xprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:17:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 12:10:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/read_conversion.h"
#include "ft_printf/print_conversion.h"
#include "ft_printf/print_utils.h"

static void	print_plaintext(const char **format, t_ctx *ctx);
static void	print_error_format(t_ctx *ctx, t_conv *conv);

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
				print_error_format(ctx, &conv);
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

static void	print_error_format(t_ctx *ctx, t_conv *conv)
{
	pf_print_char(ctx, '%');
	if (conv->hash_flag == '#')
		pf_print_char(ctx, conv->hash_flag);
	if (conv->sign_flags != '\0')
		pf_print_char(ctx, conv->sign_flags);
	if (conv->width_flags != '\0')
		pf_print_char(ctx, conv->width_flags);
	if (conv->width > 0)
		pf_print_nbr_base(ctx, ft_abs_uintmax(conv->width), "0123456789", 10);
	if (conv->has_prec)
	{
		pf_print_char(ctx, '.');
		pf_print_nbr_base(\
			ctx, ft_abs_uintmax(conv->precision), "0123456789", 10);
	}
}
