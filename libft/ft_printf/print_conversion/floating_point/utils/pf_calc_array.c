/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 12:37:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

void	pf_array_add(uint8_t *augend, uint8_t *addend, int array_size)
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

void	pf_array_half(uint8_t *dividend, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size - 1)
	{
		dividend[i + 1] += (uint8_t)((dividend[i] % 2) * 10);
		dividend[i] /= 2;
		i++;
	}
	dividend[i] /= 2;
}

void	pf_array_double(uint8_t *multiplicand, int array_size)
{
	int		i;
	uint8_t	carry;

	i = array_size - 1;
	carry = 0;
	while (i >= 0)
	{
		multiplicand[i] = (uint8_t)(multiplicand[i] * 2 + carry);
		carry = multiplicand[i] / 10;
		multiplicand[i] %= 10;
		i--;
	}
}

void	pf_array_double_hex(uint8_t *multiplicand, int array_size)
{
	int		i;
	uint8_t	carry;

	i = array_size - 1;
	carry = 0;
	while (i >= 0)
	{
		multiplicand[i] = (uint8_t)(multiplicand[i] * 2 + carry);
		carry = multiplicand[i] / 16;
		multiplicand[i] %= 16;
		i--;
	}
}
