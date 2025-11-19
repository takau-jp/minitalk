/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nan_inf_80bit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:47:42 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nan_inf_80bit(t_printf_ctx *ctx, t_my_double *my_double)
{
	char	*special_case;
	size_t	len;

	if (my_double->significand == 0)
	{
		special_case = "inf";
		if (ft_strchr("FEG", ctx->conv))
			special_case = "INF";
	}
	else
	{
		special_case = "nan";
		if (ft_strchr("FEG", ctx->conv))
			special_case = "NAN";
	}
	len = ft_strlen(special_case);
	if (my_double->sign || (my_double->sign == 0 && ctx->sign_flags))
		len++;
	if (ctx->width_flags != '-')
		ft_print_space_width(ctx, len);
	ft_print_sign(ctx, my_double->sign);
	ft_xprint_strn(ctx, special_case, ft_strlen(special_case));
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
