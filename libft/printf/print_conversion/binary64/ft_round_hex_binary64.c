/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_hex_binary64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:24:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:27:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_move_up(t_my_double_hex *my_double_hex, int precision);
static void	ft_move_up_int(t_my_double_hex *my_double_hex);
static void	ft_move_up_frac(t_my_double_hex *my_double_hex, int precision);

void	ft_round_to_nearest_even_hex_binary64(t_my_double_hex *my_double_hex,
			int precision)
{
	int	i;

	if (precision >= PF_DBL_FRAC_HEX)
		return ;
	if (my_double_hex->hex_frac[precision] > 8)
		ft_move_up(my_double_hex, precision);
	else if (my_double_hex->hex_frac[precision] == 8)
	{
		i = precision + 1;
		while (i < PF_DBL_FRAC_HEX && my_double_hex->hex_frac[i] == 0)
			i++;
		if (i != PF_DBL_FRAC_HEX)
			ft_move_up(my_double_hex, precision);
		else
		{
			if (precision == 0
				&& my_double_hex->hex_int == 1)
				ft_move_up(my_double_hex, precision);
			else if (0 < precision
				&& (my_double_hex->hex_frac[precision - 1] % 2) == 1)
				ft_move_up(my_double_hex, precision);
		}
	}
}

static void	ft_move_up(t_my_double_hex *my_double_hex, int precision)
{
	if (precision == 0)
		ft_move_up_int(my_double_hex);
	else
		ft_move_up_frac(my_double_hex, precision);
}

static void	ft_move_up_int(t_my_double_hex *my_double_hex)
{
	my_double_hex->hex_int += 1;
}

static void	ft_move_up_frac(t_my_double_hex *my_double_hex, int precision)
{
	int	i;

	i = precision - 1;
	my_double_hex->hex_frac[i] += 1;
	while (i >= 0)
	{
		if (my_double_hex->hex_frac[i] == 16)
		{
			my_double_hex->hex_frac[i] -= 16;
			if (i != 0)
				my_double_hex->hex_frac[i - 1] += 1;
			else
				ft_move_up_int(my_double_hex);
		}
		else
			return ;
		i--;
	}
}
