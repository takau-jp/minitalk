/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_darwin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:48:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:03:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_ctx	ctx;
	va_list	ap;

	ft_bzero(&ctx, sizeof(t_ctx));
	ctx.dst_type = PRINT_TO_STR;
	ctx.dst.str = str;
	ctx.dst_size = size;
	if (size != 0)
		ctx.dst.str[0] = '\0';
	va_start(ap, format);
	pf_xprintf(&ctx, &ap, format);
	va_end(ap);
	if (ctx.has_error)
		return (PF_ERROR);
	return ((int)ctx.count);
}
