/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:51:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

void	pf_print_null(t_ctx *ctx, t_conv *conv)
{
	char	*s;
	size_t	len;

	s = "(null)";
	len = ft_strlen(s);
	if (conv->has_prec && len > (size_t)conv->precision)
		len = 0;
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_strn(ctx, s, len);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}
