/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_decimal_binary64_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:09:06 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:30:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static bool	ft_convert_to_decimal_int(t_my_double *my_double);
static bool	ft_convert_to_decimal_frac(t_my_double *my_double);

bool	ft_convert_to_decimal_binary64(t_my_double *my_double)
{
	if (my_double->exponent == DBL_NAN_INF)
		return (true);
	if (!ft_convert_to_decimal_int(my_double))
		return (false);
	if (!ft_convert_to_decimal_frac(my_double))
		return (false);
	return (true);
}

/* The scaling_factor array, used for converting to decimal, stores powers of 2
	(i.e., 2⁰, 2¹, 2², ...), beginning with 2⁰ = 1.*/
static bool	ft_convert_to_decimal_int(t_my_double *my_double)
{
	int8_t	*scaling_factor;
	int		exp;
	int		n;

	if (my_double->exponent - DBL_EMAX < 0)
		return (true);
	scaling_factor = ft_calloc(PF_DBL_INT, sizeof(uint8_t));
	if (!scaling_factor)
		return (false);
	scaling_factor[PF_DBL_INT - 1] = 1;
	n = 0;
	while (n < DBL_FRACTION + 1)
	{
		if (my_double->int_binary & ((uint64_t)1 << n))
			ft_array_add(my_double->decimal_int, scaling_factor, PF_DBL_INT);
		ft_array_double(scaling_factor, PF_DBL_INT);
		n++;
	}
	exp = my_double->exponent - DBL_EMAX;
	while (n++ <= exp)
		ft_array_double(my_double->decimal_int, PF_DBL_INT);
	free(scaling_factor);
	return (true);
}

/* The scaling_factor array, used for converting to decimal, stores powers of 2
	(i.e., 2^-1, 2^-2, 2^-3, ...), beginning with 2^-1 = 0.5.*/
static bool	ft_convert_to_decimal_frac(t_my_double *my_double)
{
	int8_t	*scaling_factor;
	int		exp;
	int		n;

	if (DBL_FRACTION < my_double->exponent - DBL_EMAX)
		return (true);
	scaling_factor = ft_calloc(PF_DBL_FRAC, sizeof(uint8_t));
	if (!scaling_factor)
		return (false);
	scaling_factor[0] = 5;
	exp = my_double->exponent - DBL_EMAX;
	if (my_double->exponent == 0)
		exp = 1 - DBL_EMAX;
	while (exp++ < -1)
		ft_array_half(scaling_factor, PF_DBL_FRAC);
	n = 0;
	while (n <= DBL_FRACTION)
	{
		if (my_double->frac_binary & ((uint64_t)1 << (63 - n)))
			ft_array_add(my_double->decimal_frac, scaling_factor, PF_DBL_FRAC);
		ft_array_half(scaling_factor, PF_DBL_FRAC);
		n++;
	}
	free(scaling_factor);
	return (true);
}
