/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_percent_darwin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:40:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

void	pf_conv_percent(t_ctx *ctx, t_conv *conv)
{
	if (conv->width_flags == '\0')
		pf_print_space_width(ctx, conv, 1);
	if (conv->width_flags == '0')
		pf_print_zero_width(ctx, conv, 1);
	pf_print_char(ctx, '%');
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, 1);
}
