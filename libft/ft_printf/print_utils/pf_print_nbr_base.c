/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:53:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 12:30:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

void	pf_print_nbr_base(\
	t_ctx *ctx, uintmax_t num, char *base, size_t base_size)
{
	if (num >= base_size)
		pf_print_nbr_base(ctx, num / base_size, base, base_size);
	pf_print_char(ctx, base[num % base_size]);
}
