/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_calc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:30 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:32:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_array_add(int8_t *augend, int8_t *addend, int array_size)
{
	int	i;

	i = array_size - 1;
	while (i >= 0)
	{
		augend[i] += addend[i];
		if (augend[i] >= 10)
		{
			augend[i] -= 10;
			if (i != 0)
				augend[i - 1] += 1;
		}
		i--;
	}
}

void	ft_array_half(int8_t *dividend, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size - 1)
	{
		dividend[i + 1] += (dividend[i] % 2) * 10;
		dividend[i] /= 2;
		i++;
	}
	dividend[i] /= 2;
}

void	ft_array_double(int8_t *multiplicand, int array_size)
{
	int	i;
	int	carry;

	i = array_size - 1;
	carry = 0;
	while (i >= 0)
	{
		multiplicand[i] = multiplicand[i] * 2 + carry;
		carry = multiplicand[i] / 10;
		multiplicand[i] %= 10;
		i--;
	}
}

void	ft_array_double_hex(int8_t *multiplicand, int array_size)
{
	int	i;
	int	carry;

	i = array_size - 1;
	carry = 0;
	while (i >= 0)
	{
		multiplicand[i] = multiplicand[i] * 2 + carry;
		carry = multiplicand[i] / 16;
		multiplicand[i] %= 16;
		i--;
	}
}
