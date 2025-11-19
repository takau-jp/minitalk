/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hex_binary64.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:18:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:27:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_to_hex_int(t_my_double_hex *my_double_hex);
static void	ft_convert_to_hex_frac(t_my_double_hex *my_double_hex);

void	ft_convert_to_hex_binary64(t_my_double_hex *my_double_hex)
{
	if (my_double_hex->exponent == DBL_NAN_INF)
		return ;
	ft_convert_to_hex_int(my_double_hex);
	ft_convert_to_hex_frac(my_double_hex);
}

static void	ft_convert_to_hex_int(t_my_double_hex *my_double_hex)
{
	if (my_double_hex->exponent == 0)
		my_double_hex->hex_int = 0;
	else
		my_double_hex->hex_int = 1;
}

static void	ft_convert_to_hex_frac(t_my_double_hex *my_double_hex)
{
	int64_t	bit_mask;
	int		i;

	bit_mask = 0b1111;
	i = 0;
	while (i < PF_DBL_FRAC_HEX)
	{
		my_double_hex->hex_frac[i] = (my_double_hex->fraction
				>> (DBL_FRACTION - ((i + 1) * 4)) & bit_mask);
		i++;
	}
}
