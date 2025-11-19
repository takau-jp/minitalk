/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_hex_binary64.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:24:02 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:27:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decode_hex_binary64(double num, t_my_double_hex *my_double_hex)
{
	uint64_t	mem;

	ft_memcpy(&mem, &num, sizeof(mem));
	my_double_hex->sign = mem >> (DBL_EXPONENT + DBL_FRACTION);
	my_double_hex->exponent = (mem << DBL_SIGN) >> (DBL_SIGN + DBL_FRACTION);
	my_double_hex->fraction = (mem & (((uint64_t)1 << DBL_FRACTION) - 1));
}
