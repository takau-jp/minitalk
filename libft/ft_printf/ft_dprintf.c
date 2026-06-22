/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:48:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:03:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_ctx	ctx;
	va_list	ap;

	if (format == NULL)
		return (-1);
	ft_bzero(&ctx, sizeof(t_ctx));
	ctx.dst_type = PRINT_TO_FD;
	ctx.dst.fd = fd;
	va_start(ap, format);
	pf_xprintf(&ctx, &ap, format);
	va_end(ap);
	if (ctx.has_error)
		return (PF_ERROR);
	return ((int)ctx.count);
}
