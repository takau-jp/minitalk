/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:39:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "./character_internal.h"

static	void	print_conv_s(t_ctx *ctx, t_conv *conv, const char *s);

void	pf_conv_s(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		pf_print_null(ctx, conv);
		return ;
	}
	print_conv_s(ctx, conv, s);
}

static	void	print_conv_s(t_ctx *ctx, t_conv *conv, const char *s)
{
	size_t	len;

	if (conv->has_prec)
		len = ft_strnlen(s, conv->precision);
	else
		len = ft_strlen(s);
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_strn(ctx, s, len);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}
