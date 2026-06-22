/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:39:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

void	pf_conv_c(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	int	c;

	c = va_arg(*ap, int);
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, 1);
	pf_print_char(ctx, (char)c);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, 1);
}
