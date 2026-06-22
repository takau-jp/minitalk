/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:59:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

void	pf_print_sign(t_ctx *ctx, t_conv *conv, bool is_negative)
{
	if (is_negative)
		pf_print_char(ctx, '-');
	else if (!is_negative && conv->sign_flags == '+')
		pf_print_char(ctx, '+');
	else if (!is_negative && conv->sign_flags == ' ')
		pf_print_char(ctx, ' ');
}
