/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_decimal_80bit.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:09:06 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:27:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_convert_to_decimal_int(t_my_double *my_double);
static bool	ft_convert_to_decimal_frac(t_my_double *my_double);

bool	ft_convert_to_decimal_80bit(t_my_double *my_double)
{
	if (my_double->exponent == LDBL_NAN_INF)
		return (true);
	if (!ft_convert_to_decimal_int(my_double))
		return (false);
	if (!ft_convert_to_decimal_frac(my_double))
		return (false);
	return (true);
}

static bool	ft_convert_to_decimal_int(t_my_double *my_double)
{
	int8_t	*scaling_factor;
	int		exp;
	int		n;

	if (my_double->exponent - LDBL_EMAX < 0)
		return (true);
	scaling_factor = ft_calloc(PF_LDBL_INT, sizeof(uint8_t));
	if (!scaling_factor)
		return (false);
	scaling_factor[PF_LDBL_INT - 1] = 1;
	n = 0;
	while (n < LDBL_FRACTION + 1)
	{
		if (my_double->int_binary & ((uint64_t)1 << n))
			ft_array_add(my_double->decimal_int, scaling_factor, PF_LDBL_INT);
		ft_array_double(scaling_factor, PF_LDBL_INT);
		n++;
	}
	exp = my_double->exponent - LDBL_EMAX;
	while (n++ <= exp)
		ft_array_double(my_double->decimal_int, PF_LDBL_INT);
	free(scaling_factor);
	return (true);
}

static bool	ft_convert_to_decimal_frac(t_my_double *my_double)
{
	int8_t	*scaling_factor;
	int		exp;
	int		n;

	if (LDBL_FRACTION < my_double->exponent - LDBL_EMAX)
		return (true);
	scaling_factor = ft_calloc(PF_LDBL_FRAC, sizeof(uint8_t));
	if (!scaling_factor)
		return (false);
	scaling_factor[0] = 5;
	exp = my_double->exponent - LDBL_EMAX;
	if (my_double->exponent == 0)
		exp = 1 - LDBL_EMAX;
	while (exp++ < -1)
		ft_array_half(scaling_factor, PF_LDBL_FRAC);
	n = 0;
	while (n <= LDBL_FRACTION)
	{
		if (my_double->frac_binary & ((uint64_t)1 << (63 - n)))
			ft_array_add(my_double->decimal_frac, scaling_factor, PF_LDBL_FRAC);
		ft_array_half(scaling_factor, PF_LDBL_FRAC);
		n++;
	}
	free(scaling_factor);
	return (true);
}
