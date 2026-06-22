/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_repeated_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 12:34:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "../print_utils_internal.h"

void	pf_print_repeated_char(t_ctx *ctx, char c, size_t count)
{
	char	buf[WRITE_BLOCK_SIZE];
	size_t	len;

	if (count == 0)
		return ;
	if (count <= WRITE_BLOCK_SIZE)
		len = count;
	else
		len = WRITE_BLOCK_SIZE;
	ft_memset(buf, c, len);
	while (count > 0)
	{
		pf_print_strn(ctx, buf, len);
		count -= len;
		if (count <= WRITE_BLOCK_SIZE)
			len = count;
	}
}
