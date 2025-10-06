/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_decimal_exponent_binary64_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:49:55 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_get_decimal_exponent_binary64(t_my_double *my_double)
{
	int	i;
	int	decimal_exponent;

	decimal_exponent = 0;
	if (my_double->significand == 0)
		return (0);
	i = 0;
	if (my_double->int_binary)
	{
		while (i < PF_DBL_INT && my_double->decimal_int[i] == 0)
			i++;
		decimal_exponent = PF_DBL_INT - i - 1;
	}
	else
	{
		while (i < PF_DBL_FRAC && my_double->decimal_frac[i] == 0)
			i++;
		decimal_exponent = -(i + 1);
	}
	return (decimal_exponent);
}
