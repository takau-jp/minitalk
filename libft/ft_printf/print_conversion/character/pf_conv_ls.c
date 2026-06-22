/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:46:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:28:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "./character_internal.h"

static void		print_conv_ls(\
					t_ctx *ctx, t_conv *conv, const wchar_t *ws);
static bool		compute_utf8_str_len(\
					t_conv *conv, const wchar_t *ws, size_t *len);
static void		encode_utf8_str(\
					const wchar_t *ws, unsigned char *utf8_str, size_t len);

void	pf_conv_ls(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	wchar_t	*ws;

	ws = va_arg(*ap, wchar_t *);
	if (ws == NULL)
	{
		pf_print_null(ctx, conv);
		return ;
	}
	print_conv_ls(ctx, conv, ws);
}

static void	print_conv_ls(t_ctx *ctx, t_conv *conv, const wchar_t *ws)
{
	unsigned char	*utf8_str;
	size_t			len;

	if (!compute_utf8_str_len(conv, ws, &len))
	{
		ctx->has_error = true;
		return ;
	}
	utf8_str = malloc(sizeof(unsigned char) * len);
	if (utf8_str == NULL)
	{
		ctx->has_error = true;
		return ;
	}
	encode_utf8_str(ws, utf8_str, len);
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_utf8(ctx, utf8_str, len);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
	free(utf8_str);
}

static bool	compute_utf8_str_len(
	t_conv *conv, const wchar_t *ws, size_t *len)
{
	size_t	res;

	*len = 0;
	while (*ws != 0x0)
	{
		if (!pf_validate_codepoint(*ws))
			return (false);
		res = pf_calc_utf8_len(*ws);
		if (conv->has_prec && *len + res > (size_t)conv->precision)
			break ;
		*len += res;
		ws++;
	}
	return (true);
}

static void	encode_utf8_str(
	const wchar_t *ws, unsigned char *utf8_str, size_t len)
{
	size_t	current_len;

	current_len = 0;
	while (current_len < len)
	{
		pf_encode_utf8(*ws, utf8_str + current_len);
		current_len += pf_calc_utf8_len(*ws);
		ws++;
	}
}
