/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:29:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_null(t_printf_ctx *ctx);
static void		ft_print_ls(t_printf_ctx *ctx, const wchar_t *ws);
static size_t	ft_encode_wchar_str_to_utf8(t_printf_ctx *ctx,
					unsigned char **utf8_str, const wchar_t *ws);

void	ft_conv_ls(va_list *ap, t_printf_ctx *ctx)
{
	wchar_t	*ws;

	ws = va_arg(*ap, wchar_t *);
	if (!ws)
	{
		ft_print_null(ctx);
		return ;
	}
	ft_print_ls(ctx, ws);
}

static void	ft_print_null(t_printf_ctx *ctx)
{
	char	*s;
	size_t	len;

	s = "(null)";
	len = ft_strlen(s);
	if (ctx->has_prec && len > (size_t)ctx->precision)
		len = 0;
	if (!ctx->width_flags || ctx->width_flags == '0')
		ft_print_space_width(ctx, len);
	ft_xprint_strn(ctx, s, len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

static void	ft_print_ls(t_printf_ctx *ctx, const wchar_t *ws)
{
	unsigned char	*utf8_str;
	size_t			len;

	len = ft_encode_wchar_str_to_utf8(ctx, &utf8_str, ws);
	if (!utf8_str)
	{
		ctx->res = -1;
		return ;
	}
	if (!ctx->width_flags || ctx->width_flags == '0')
		ft_print_space_width(ctx, len);
	ft_print_utf8(ctx, utf8_str, len);
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
	free(utf8_str);
}

static size_t	ft_encode_wchar_str_to_utf8(t_printf_ctx *ctx,
					unsigned char **utf8_str, const wchar_t *ws)
{
	size_t			len;
	unsigned char	utf8[5];
	unsigned char	*tmp;

	len = 0;
	*utf8_str = (unsigned char *)ft_strdup("\0");
	if (!*utf8_str)
		return (0);
	while ((!ctx->has_prec || len < (size_t)ctx->precision) && *ws)
	{
		ft_encode_wchar_to_utf8(utf8, *ws);
		if (!ctx->has_prec
			|| len + ft_strlen((char *)utf8) <= (size_t)ctx->precision)
		{
			tmp = (unsigned char *)ft_strjoin((char *)*utf8_str, (char *)utf8);
			free(*utf8_str);
			*utf8_str = tmp;
			if (!*utf8_str)
				return (0);
			len += ft_strlen((char *)utf8);
		}
		ws++;
	}
	return (len);
}
