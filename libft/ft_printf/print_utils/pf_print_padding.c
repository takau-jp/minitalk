/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:59:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:35:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./print_utils_internal.h"

void	pf_print_padding(t_ctx *ctx, size_t padding)
{
	pf_print_repeated_char(ctx, '0', padding);
}
