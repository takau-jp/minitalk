/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 01:44:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/12 15:23:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_utf8_to_fd(\
				t_printf_ctx *ctx, unsigned char *utf8_str, size_t len);
static void	ft_print_utf8_to_str(\
				t_printf_ctx *ctx, unsigned char *utf8_str, size_t len);

void	ft_encode_wchar_to_utf8(unsigned char utf8[5], const wchar_t wc)
{
	ft_bzero(utf8, 5);
	if (0x0000 <= wc && wc <= 0x007F)
		utf8[0] = ((char)(wc & 0b01111111)) | 0b00000000;
	else if (0x0080 <= wc && wc <= 0x07FF)
	{
		utf8[0] = ((char)((wc >> 6) & 0b00011111)) | 0b11000000;
		utf8[1] = ((char)(wc & 0b00111111)) | 0b10000000;
	}
	else if (0x0800 <= wc && wc <= 0xFFFF)
	{
		utf8[0] = ((char)((wc >> 12) & 0b00001111)) | 0b11100000;
		utf8[1] = ((char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[2] = ((char)(wc & 0b00111111)) | 0b10000000;
	}
	else if (0x10000 <= wc && wc <= 0x10FFFF)
	{
		utf8[0] = ((char)((wc >> 18) & 0b00000111)) | 0b11110000;
		utf8[1] = ((char)((wc >> 12) & 0b00111111)) | 0b10000000;
		utf8[2] = ((char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[3] = ((char)(wc & 0b00111111)) | 0b10000000;
	}
}

bool	ft_is_utf8_leading_byte(unsigned char byte)
{
	return ((byte & 0b11000000) != 0b10000000);
}

void	ft_print_utf8(
			t_printf_ctx *ctx, unsigned char *utf8_str, size_t len)
{
	if (ctx->dst_type == PRINT_TO_FD)
		ft_print_utf8_to_fd(ctx, utf8_str, len);
	else
		ft_print_utf8_to_str(ctx, utf8_str, len);
}

static void	ft_print_utf8_to_fd(
			t_printf_ctx *ctx, unsigned char *utf8_str, size_t len)
{
	if (ctx->res < 0 || len == 0)
		return ;
	if (PRINTF_RESULT_LIMIT < (size_t)ctx->res + len)
	{
		len = PRINTF_RESULT_LIMIT - ctx->res;
		while (!ft_is_utf8_leading_byte(utf8_str[len]))
			len++;
		ctx->res = -1;
	}
	if (!ft_write_to_fd(ctx->fd, (char *)utf8_str, len))
		ctx->res = -1;
	if (ctx->res >= 0)
		ctx->res += len;
}

static void	ft_print_utf8_to_str(
			t_printf_ctx *ctx, unsigned char *utf8_str, size_t len)
{
	size_t	i;

	if (ctx->res < 0 || len == 0)
		return ;
	if (ctx->dst_type == PRINT_TO_STR \
		&& ctx->str_size < (size_t)ctx->res + 1 + len)
	{
		i = ctx->str_size - 1 - (size_t)ctx->res;
		while (i > 0 && !ft_is_utf8_leading_byte(utf8_str[i--]))
			ctx->str_size--;
	}
	if (PRINTF_RESULT_LIMIT < (size_t)ctx->res + len)
	{
		i = PRINTF_RESULT_LIMIT - (size_t)ctx->res;
		ctx->str_size = PRINTF_RESULT_LIMIT;
		while (i > 0 && !ft_is_utf8_leading_byte(utf8_str[i--]))
			ctx->str_size--;
		ctx->res = -1;
	}
	if (ctx->str != NULL)
		ft_strlcat(ctx->str + ctx->res, (char *)utf8_str, \
			ft_min_size(ctx->str_size - ctx->res, len + 1));
	if (ctx->res >= 0)
		ctx->res += len;
}
