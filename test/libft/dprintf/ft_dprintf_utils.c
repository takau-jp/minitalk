/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:33:57 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 18:58:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_dprint_char(t_dprintf_ctx *ctx, int c)
{
	if (PRINTF_RESULT_LIMIT == ctx->res)
		ctx->res = -1;
	if (ctx->res < 0)
		return ;
	if (write(ctx->fd, &c, 1) != 1)
		ctx->res = -1;
	if (ctx->res >= 0)
		ctx->res += 1;
}

void	ft_dprint_strn(t_dprintf_ctx *ctx, char *s, size_t len)
{
	if (ctx->res < 0 || len == 0)
		return ;
	if (PRINTF_RESULT_LIMIT < (size_t)ctx->res + len)
	{
		len = PRINTF_RESULT_LIMIT - ctx->res;
		ctx->res = -1;
	}
	if (!ft_fd_write_strn(ctx->fd, s, len))
		ctx->res = -1;
	if (ctx->res >= 0)
		ctx->res += len;
}

bool	ft_fd_write_strn(int fd, char *s, size_t len)
{
	size_t	chunk;
	ssize_t	write_res;

	while (len > 0)
	{
		chunk = WRITE_BLOCK_SIZE;
		if (WRITE_BLOCK_SIZE > len)
			chunk = len;
		write_res = write(fd, s, chunk);
		if (write_res == -1)
			return (false);
		else if (write_res == 0)
			return (true);
		s += write_res;
		len -= write_res;
	}
	return (true);
}

void	ft_print_hexa_preffix(t_dprintf_ctx *ctx)
{
	if (ft_strchr("xpa", ctx->conv))
		ft_dprint_strn(ctx, "0x", 2);
	else if (ft_strchr("XA", ctx->conv))
		ft_dprint_strn(ctx, "0X", 2);
}
