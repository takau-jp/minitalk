/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:54:00 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:48:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf_ctx	ctx;
	va_list			ap;

	if (!format)
		return (-1);
	ft_bzero(&ctx, sizeof(t_printf_ctx));
	ctx.dst_type = PRINT_TO_FD;
	ctx.fd = STDOUT_FILENO;
	va_start(ap, format);
	ft_xprint_format(&ctx, &ap, format);
	va_end(ap);
	return (ctx.res);
}
