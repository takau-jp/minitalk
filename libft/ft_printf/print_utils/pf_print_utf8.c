/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 00:45:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:03:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "../print_conversion/character/character_internal.h"

static void	pf_print_utf8_to_fd(\
				t_ctx *ctx, const unsigned char *utf8_str, size_t len);
static void	pf_print_utf8_to_str(\
				t_ctx *ctx, const unsigned char *utf8_str, size_t len);
static bool	is_utf8_leading_byte(unsigned char byte);

void	pf_print_utf8(t_ctx *ctx, const unsigned char *utf8_str, size_t len)
{
	if (ctx->has_error || len == 0)
		return ;
	if (PRINTF_RESULT_LIMIT < ctx->count + len)
	{
		len = PRINTF_RESULT_LIMIT - ctx->count;
		ctx->has_error = true;
	}
	if (ctx->dst_type == PRINT_TO_FD)
		pf_print_utf8_to_fd(ctx, utf8_str, len);
	else if (ctx->dst_type == PRINT_TO_STR)
		pf_print_utf8_to_str(ctx, utf8_str, len);
	ctx->count += len;
}

static void	pf_print_utf8_to_fd(
	t_ctx *ctx, const unsigned char *utf8_str, size_t len)
{
	size_t	size;
	ssize_t	write_res;

	while (len > 0)
	{
		if (PIPE_BUF >= len)
			size = len;
		else
		{
			size = PIPE_BUF;
			while (!is_utf8_leading_byte(utf8_str[size]))
				size--;
		}
		write_res = write(ctx->dst.fd, utf8_str, size);
		if (write_res == -1 || write_res == 0 \
			|| ((size_t)write_res != size \
				&& !is_utf8_leading_byte(utf8_str[write_res])))
		{
			ctx->has_error = true;
			return ;
		}
		utf8_str += write_res;
		len -= write_res;
	}
}

static void	pf_print_utf8_to_str(
	t_ctx *ctx, const unsigned char *utf8_str, size_t len)
{
	size_t	append_size;

	if (ctx->dst_size <= ctx->count + 1)
		return ;
	if (ctx->dst_size - ctx->count < len + 1)
	{
		while (!is_utf8_leading_byte(utf8_str[ctx->dst_size - ctx->count - 1]))
			ctx->dst_size--;
	}
	if (ctx->dst_size - ctx->count < len + 1)
		append_size = ctx->dst_size - ctx->count;
	else
		append_size = len + 1;
	ft_strlcat(ctx->dst.str + ctx->count, (const char *)utf8_str, append_size);
}

static bool	is_utf8_leading_byte(unsigned char byte)
{
	return ((byte & UTF8_TOP2_MASK) != UTF8_CONT_MARKER);
}
