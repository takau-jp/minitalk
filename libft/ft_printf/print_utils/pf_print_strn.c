/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_strn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:56:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:04:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "./print_utils_internal.h"

static void	pf_print_to_fd(t_ctx *ctx, const char *s, size_t len);
static void	pf_print_to_str(t_ctx *ctx, const char *s, size_t len);

void	pf_print_strn(t_ctx *ctx, const char *s, size_t len)
{
	if (ctx->has_error || len == 0)
		return ;
	if (PRINTF_RESULT_LIMIT < ctx->count + len)
	{
		len = PRINTF_RESULT_LIMIT - ctx->count;
		ctx->has_error = true;
	}
	if (ctx->dst_type == PRINT_TO_FD)
		pf_print_to_fd(ctx, s, len);
	else if (ctx->dst_type == PRINT_TO_STR)
		pf_print_to_str(ctx, s, len);
	ctx->count += len;
}

static void	pf_print_to_fd(t_ctx *ctx, const char *s, size_t len)
{
	size_t	chunk;
	ssize_t	write_res;

	while (len > 0)
	{
		chunk = WRITE_BLOCK_SIZE;
		if (WRITE_BLOCK_SIZE > len)
			chunk = len;
		write_res = write(ctx->dst.fd, s, chunk);
		if (write_res == -1 || write_res == 0)
		{
			ctx->has_error = true;
			return ;
		}
		s += write_res;
		len -= write_res;
	}
}

static void	pf_print_to_str(t_ctx *ctx, const char *s, size_t len)
{
	size_t	append_size;

	if (ctx->dst_size <= ctx->count)
		return ;
	if (ctx->dst_size - ctx->count < len + 1)
		append_size = ctx->dst_size - ctx->count;
	else
		append_size = len + 1;
	ft_strlcat(ctx->dst.str + ctx->count, s, append_size);
}
