/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_hex_binary64_darwin_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:27:12 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_normalize_hex_binary64(t_my_double_hex *my_double_hex)
{
	my_double_hex->exponent += 1;
	while (my_double_hex->hex_frac[0] < 8)
	{
		ft_array_double_hex(my_double_hex->hex_frac, PF_DBL_FRAC_HEX);
		my_double_hex->exponent--;
	}
	ft_array_double_hex(my_double_hex->hex_frac, PF_DBL_FRAC_HEX);
	my_double_hex->exponent--;
	my_double_hex->hex_int = 1;
}
