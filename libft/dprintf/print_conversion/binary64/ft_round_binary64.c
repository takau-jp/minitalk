/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_binary64_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:35:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_move_up(t_my_double *my_double, int precision);
static void	ft_move_up_int(t_my_double *my_double);
static void	ft_move_up_frac(t_my_double *my_double, int precision);

void	ft_round_to_nearest_even_binary64(t_my_double *my_double, int precision)
{
	int	i;

	if (precision >= PF_DBL_FRAC)
		return ;
	if (my_double->decimal_frac[precision] > 5)
		ft_move_up(my_double, precision);
	else if (my_double->decimal_frac[precision] == 5)
	{
		i = precision + 1;
		while (i < PF_DBL_FRAC && my_double->decimal_frac[i] == 0)
			i++;
		if (i != PF_DBL_FRAC)
			ft_move_up(my_double, precision);
		else
		{
			if (precision == 0
				&& (my_double->decimal_int[PF_DBL_INT - 1] % 2) == 1)
				ft_move_up(my_double, precision);
			else if (0 < precision
				&& (my_double->decimal_frac[precision - 1] % 2) == 1)
				ft_move_up(my_double, precision);
		}
	}
}

static void	ft_move_up(t_my_double *my_double, int precision)
{
	if (precision == 0)
		ft_move_up_int(my_double);
	else
		ft_move_up_frac(my_double, precision);
}

static void	ft_move_up_int(t_my_double *my_double)
{
	int	i;

	i = PF_DBL_INT - 1;
	my_double->decimal_int[i] += 1;
	while (i >= 0)
	{
		if (my_double->decimal_int[i] == 10)
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

static void	ft_move_up_frac(t_my_double *my_double, int precision)
{
	int	i;

	i = precision - 1;
	my_double->decimal_frac[i] += 1;
	while (i >= 0)
	{
		if (my_double->decimal_frac[i] == 10)
		{
			my_double->decimal_frac[i] -= 10;
			if (i != 0)
				my_double->decimal_frac[i - 1] += 1;
			else
				ft_move_up_int(my_double);
		}
		else
			return ;
		i--;
	}
}
