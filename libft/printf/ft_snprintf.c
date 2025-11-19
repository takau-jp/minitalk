/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:49:48 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 22:53:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_printf_ctx	ctx;
	va_list			ap;

	if (!format)
		return (-1);
	ft_bzero(&ctx, sizeof(t_printf_ctx));
	ctx.dst_type = PRINT_TO_STR;
	ctx.str = str;
	ctx.str_size = size;
	if (size != 0)
		ctx.str[0] = '\0';
	va_start(ap, format);
	ft_xprint_format(&ctx, &ap, format);
	va_end(ap);
	return (ctx.res);
}
