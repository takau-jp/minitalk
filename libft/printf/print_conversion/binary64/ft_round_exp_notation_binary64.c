/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_exp_notation_binary64.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:35:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:27:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_round_to_nearest_even_int_part(
				t_my_double *my_double, int round_digit);
static void	ft_move_up_int_n(t_my_double *my_double, int digit);

void	ft_round_to_nearest_even_exp_notation_binary64(t_my_double *my_double,
			int precision)
{
	int	i;

	i = 0;
	if (my_double->int_binary == 0)
	{
		while (i < PF_DBL_FRAC && my_double->decimal_frac[i] == 0)
			i++;
		ft_round_to_nearest_even_binary64(my_double,
			i + 1 + precision);
		return ;
	}
	while (i < PF_DBL_INT && my_double->decimal_int[i] == 0)
		i++;
	if (i + 1 + precision < PF_DBL_INT)
		ft_round_to_nearest_even_int_part(my_double, i + 1 + precision);
	else
		ft_round_to_nearest_even_binary64(my_double,
			precision - (PF_DBL_INT - i - 1));
}

static void	ft_round_to_nearest_even_int_part(
				t_my_double *my_double, int round_digit)
{
	int	i;

	if (my_double->decimal_int[round_digit] > 5)
		ft_move_up_int_n(my_double, round_digit - 1);
	else if (my_double->decimal_int[round_digit] == 5)
	{
		i = round_digit + 1;
		while (i < PF_DBL_INT && my_double->decimal_int[i] == 0)
			i++;
		if (i != PF_DBL_INT && my_double->frac_binary)
			ft_move_up_int_n(my_double, round_digit - 1);
		else if ((my_double->decimal_int[round_digit - 1] % 2) == 1)
			ft_move_up_int_n(my_double, round_digit - 1);
	}
}

static void	ft_move_up_int_n(t_my_double *my_double, int digit)
{
	int	i;

	i = digit;
	my_double->decimal_int[i] += 1;
	while (i >= 0)
	{
		if (my_double->decimal_int[i] >= 10)
		{
			my_double->decimal_int[i] -= 10;
			if (i != 0)
				my_double->decimal_int[i - 1] += 1;
		}
		else
			return ;
		i--;
	}
}
