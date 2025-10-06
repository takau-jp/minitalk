/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_80bit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:45:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:30:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	ft_get_int_binary(t_my_double *my_double);
static void	ft_get_frac_binary(t_my_double *my_double);

// Little endian assumption: first get right, then left
void	ft_decode_80bit(long double num, t_my_double *my_double)
{
	uint64_t	right_mem;
	uint16_t	left_mem;
	int			ldbl_fraction;

	ft_memcpy(&(right_mem), (char *)&num, sizeof(uint64_t));
	ft_memcpy(&(left_mem), (char *)&num + sizeof(uint64_t), sizeof(uint16_t));
	my_double->sign = (left_mem >> (LDBL_EXPONENT)) & (uint16_t)1;
	my_double->exponent = left_mem & (((uint16_t)1 << LDBL_EXPONENT) - 1);
	ldbl_fraction = LDBL_FRACTION;
	my_double->significand = right_mem & (((uint64_t)1 << ldbl_fraction) - 1);
	if (my_double->exponent == LDBL_NAN_INF)
		return ;
	my_double->significand |= (right_mem & ((uint64_t)1 << ldbl_fraction));
	ft_get_int_binary(my_double);
	ft_get_frac_binary(my_double);
}

static void	ft_get_int_binary(t_my_double *my_double)
{
	int	offset;

	if (my_double->exponent == LDBL_NAN_INF)
		return ;
	if (my_double->exponent - LDBL_EMAX < 0)
		return ;
	if (my_double->exponent - LDBL_EMAX <= LDBL_FRACTION)
		offset = my_double->exponent - LDBL_EMAX;
	else
		offset = LDBL_FRACTION;
	my_double->int_binary = my_double->significand >> (LDBL_FRACTION - offset);
}

static void	ft_get_frac_binary(t_my_double *my_double)
{
	int	offset;

	if (my_double->exponent == LDBL_NAN_INF)
		return ;
	if (LDBL_FRACTION < my_double->exponent - LDBL_EMAX)
		return ;
	offset = 64 - LDBL_FRACTION;
	if (my_double->exponent - LDBL_EMAX < 0)
		offset -= 1;
	else
		offset += my_double->exponent - LDBL_EMAX;
	my_double->frac_binary = my_double->significand << offset;
}
