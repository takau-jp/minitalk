/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_binary64_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:45:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_get_int_binary(t_my_double *my_double);
static void	ft_get_frac_binary(t_my_double *my_double);

void	ft_decode_binary64(double num, t_my_double *my_double)
{
	uint64_t	mem;

	ft_memcpy(&mem, &num, sizeof(mem));
	my_double->sign = mem >> (DBL_EXPONENT + DBL_FRACTION);
	my_double->exponent = (mem << DBL_SIGN) >> (DBL_SIGN + DBL_FRACTION);
	my_double->significand = (mem & (((uint64_t)1 << DBL_FRACTION) - 1));
	if (my_double->exponent == DBL_NAN_INF)
		return ;
	if (my_double->exponent != 0)
		my_double->significand |= ((uint64_t)1 << DBL_FRACTION);
	ft_get_int_binary(my_double);
	ft_get_frac_binary(my_double);
}

static void	ft_get_int_binary(t_my_double *my_double)
{
	int	offset;

	if (my_double->exponent == DBL_NAN_INF)
		return ;
	if (my_double->exponent - DBL_EMAX < 0)
		return ;
	if (my_double->exponent - DBL_EMAX <= DBL_FRACTION)
		offset = my_double->exponent - DBL_EMAX;
	else
		offset = DBL_FRACTION;
	my_double->int_binary = my_double->significand >> (DBL_FRACTION - offset);
}

static void	ft_get_frac_binary(t_my_double *my_double)
{
	int	offset;

	if (my_double->exponent == DBL_NAN_INF)
		return ;
	if (DBL_FRACTION < my_double->exponent - DBL_EMAX)
		return ;
	offset = 64 - DBL_FRACTION;
	if (my_double->exponent - DBL_EMAX < 0)
		offset -= 1;
	else
		offset += my_double->exponent - DBL_EMAX;
	my_double->frac_binary = my_double->significand << offset;
}
