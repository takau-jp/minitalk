/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_calc_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 22:56:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

#include "../ft_strtod_internal.h"

static void	update_msd_and_lsd(t_to_double *to_double);

void	strtod_half_array(t_to_double *to_double)
{
	uint8_t	*left;
	uint8_t	*right;
	uint8_t	carry;

	left = to_double->msd;
	right = to_double->lsd;
	if (left == NULL || right == NULL)
		return ;
	carry = 0;
	while (left <= right)
	{
		*left += carry * to_double->base;
		carry = *left % 2;
		*left = *left / 2;
		++left;
	}
	if (carry != 0 && left <= to_double->end)
	{
		*left = (carry * to_double->base) / 2;
		to_double->lsd = left;
	}
	update_msd_and_lsd(to_double);
}

void	strtod_double_array(t_to_double *to_double)
{
	uint8_t	*left;
	uint8_t	*right;
	uint8_t	carry;

	left = to_double->msd;
	right = to_double->lsd;
	if (left == NULL || right == NULL)
		return ;
	carry = 0;
	while (left <= right)
	{
		*right = *right * 2 + carry;
		carry = *right / to_double->base;
		*right %= to_double->base;
		--right;
	}
	if (carry != 0 && to_double->fixed_point <= right)
	{
		*right = carry;
		to_double->msd = right;
	}
	update_msd_and_lsd(to_double);
}

static void	update_msd_and_lsd(t_to_double *to_double)
{
	if (to_double->msd == NULL || to_double->lsd == NULL)
		return ;
	while (to_double->msd <= to_double->lsd)
	{
		if (*(to_double->msd) != 0)
			break ;
		++(to_double->msd);
	}
	if (to_double->msd > to_double->lsd)
	{
		to_double->msd = NULL;
		to_double->lsd = NULL;
		return ;
	}
	while (to_double->msd <= to_double->lsd)
	{
		if (*(to_double->lsd) != 0)
			break ;
		--(to_double->lsd);
	}
}
