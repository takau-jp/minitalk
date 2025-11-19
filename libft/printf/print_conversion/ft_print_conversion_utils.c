/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:17:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space_width(t_printf_ctx *ctx, size_t len)
{
	char	*buf;
	size_t	buf_size;

	if (ctx->width <= 0 || (size_t)ctx->width <= len)
		return ;
	buf_size = ctx->width - len;
	buf = (char *)malloc(buf_size);
	if (!buf)
	{
		ctx->res = -1;
		return ;
	}
	ft_memset(buf, ' ', buf_size);
	ft_xprint_strn(ctx, buf, buf_size);
	free(buf);
}

void	ft_print_zero_width(t_printf_ctx *ctx, size_t len)
{
	char	*buf;
	size_t	buf_size;

	if (ctx->width <= 0 || (size_t)ctx->width <= len)
		return ;
	buf_size = ctx->width - len;
	buf = (char *)malloc(buf_size);
	if (!buf)
	{
		ctx->res = -1;
		return ;
	}
	ft_memset(buf, '0', buf_size);
	ft_xprint_strn(ctx, buf, buf_size);
	free(buf);
}

void	ft_print_padding(t_printf_ctx *ctx, size_t padding)
{
	char	*buf;
	size_t	buf_size;

	if (padding == 0)
		return ;
	buf_size = padding;
	buf = (char *)malloc(buf_size);
	if (!buf)
	{
		ctx->res = -1;
		return ;
	}
	ft_memset(buf, '0', buf_size);
	ft_xprint_strn(ctx, buf, buf_size);
	free(buf);
}

void	ft_print_sign(t_printf_ctx *ctx, bool is_negative)
{
	if (is_negative)
		ft_xprint_char(ctx, '-');
	else if (!is_negative && ctx->sign_flags == '+')
		ft_xprint_char(ctx, '+');
	else if (!is_negative && ctx->sign_flags == ' ')
		ft_xprint_char(ctx, ' ');
}
