/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_conversion_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:59:22 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_conversion(t_printf_ctx *ctx)
{
	ctx->conv = 0;
	ctx->hash_flag = 0;
	ctx->sign_flags = 0;
	ctx->width_flags = 0;
	ctx->width = 0;
	ctx->has_prec = false;
	ctx->precision = 0;
	ctx->length[0] = 0;
	ctx->length[1] = 0;
	ctx->length[2] = 0;
}

bool	ft_check_int_overflow(const char *format)
{
	long	n;

	n = 0;
	while (ft_isdigit(*format))
	{
		n = n * 10 + (*format - '0');
		if (INT_MAX < n)
			return (true);
		format++;
	}
	return (false);
}

int	ft_atoi_precision(const char *format)
{
	int	num;

	num = 0;
	while (ft_isdigit(*format))
	{
		num = num * 10 + (*format - '0');
		format++;
	}
	return (num);
}
