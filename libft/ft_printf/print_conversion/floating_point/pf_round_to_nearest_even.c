/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_round_to_nearest_even.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:45:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./floating_point_internal.h"

static void	move_up(t_pf_float *fp, int digit);

/*
Rounds fp->print_buf at position 'precision' using round-half-to-even
(Banker's rounding, IEEE 754 default rounding mode).
precision >= 0: rounding position is in the fractional part
precision <  0: rounding position is in the integer part (used by %g)

Rules at radix_point[precision]:
  digit > base/2                            : round up
  digit == base/2 and nonzero remainder     : round up (not truly halfway)
  digit == base/2 and preceding digit is odd: round up (round to even)
  otherwise                                 : truncate
*/
void	pf_round_to_nearest_even(t_pf_float *fp, int precision)
{
	int	i;

	if (precision <= -(fp->buf_int_size) || fp->buf_frac_size <= precision)
		return ;
	if (fp->radix_point[precision] > fp->base / 2)
		move_up(fp, precision - 1);
	else if (fp->radix_point[precision] == fp->base / 2)
	{
		i = precision + 1;
		while (i < fp->buf_frac_size && fp->radix_point[i] == 0)
			i++;
		if (i < fp->buf_frac_size)
			move_up(fp, precision - 1);
		else if ((fp->radix_point[precision - 1] % 2) == 1)
			move_up(fp, precision - 1);
	}
}

/*
Increments the digit at 'digit' and propagates carry toward higher digits.
Uses radix_point with negative indices to access the integer part,
allowing carry to cross the decimal point without branching.
*/
static void	move_up(t_pf_float *fp, int digit)
{
	fp->radix_point[digit] += 1;
	while (digit >= -(fp->buf_int_size))
	{
		if (fp->radix_point[digit] < fp->base)
			return ;
		fp->radix_point[digit] -= fp->base;
		fp->radix_point[digit - 1] += 1;
		digit--;
	}
}
