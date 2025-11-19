/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_darwin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:38:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:46:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_printf_ctx	ctx;
	va_list			ap;

	ft_bzero(&ctx, sizeof(t_printf_ctx));
	ctx.dst_type = PRINT_TO_FD;
	ctx.fd = fd;
	va_start(ap, format);
	ft_xprint_format(&ctx, &ap, format);
	va_end(ap);
	return (ctx.res);
}
