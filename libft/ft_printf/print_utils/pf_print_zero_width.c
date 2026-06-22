/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_zero_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:59:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:35:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./print_utils_internal.h"

void	pf_print_zero_width(t_ctx *ctx, t_conv *conv, size_t len)
{
	if (conv->width <= 0 || (size_t)conv->width <= len)
		return ;
	pf_print_repeated_char(ctx, '0', conv->width - len);
}
