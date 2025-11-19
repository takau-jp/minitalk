/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:33:57 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/12 15:25:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xprint_char(t_printf_ctx *ctx, int c)
{
	char	s[2];

	if (PRINTF_RESULT_LIMIT == ctx->res)
		ctx->res = -1;
	if (ctx->res < 0)
		return ;
	if (ctx->dst_type == PRINT_TO_FD && write(ctx->fd, &c, 1) != 1)
		ctx->res = -1;
	else if (ctx->dst_type == PRINT_TO_STR)
	{
		s[0] = c;
		s[1] = '\0';
		ft_strlcat(ctx->str + ctx->res, s, \
			ft_min_size(ctx->str_size - ctx->res, 2));
	}
	if (ctx->res >= 0)
		ctx->res += 1;
}

void	ft_xprint_strn(t_printf_ctx *ctx, char *s, size_t len)
{
	if (ctx->res < 0 || len == 0)
		return ;
	if (PRINTF_RESULT_LIMIT < (size_t)ctx->res + len)
	{
		if (ctx->dst_type == PRINT_TO_FD)
			len = PRINTF_RESULT_LIMIT - ctx->res;
		else if (ctx->dst_type == PRINT_TO_STR)
			ctx->str_size = (size_t)PRINTF_RESULT_LIMIT + 1;
		ctx->res = -1;
	}
	if (ctx->dst_type == PRINT_TO_FD && !ft_write_to_fd(ctx->fd, s, len))
		ctx->res = -1;
	else if (ctx->dst_type == PRINT_TO_STR && ctx->str != NULL)
		ft_strlcat(ctx->str + ctx->res, s, \
			ft_min_size(ctx->str_size - ctx->res, len + 1));
	if (ctx->res >= 0)
		ctx->res += len;
}

bool	ft_write_to_fd(int fd, char *s, size_t len)
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

size_t	ft_min_size(size_t	num1, size_t num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

void	ft_print_hexa_preffix(t_printf_ctx *ctx)
{
	if (ft_strchr("xpa", ctx->conv))
		ft_xprint_strn(ctx, "0x", 2);
	else if (ft_strchr("XA", ctx->conv))
		ft_xprint_strn(ctx, "0X", 2);
}
