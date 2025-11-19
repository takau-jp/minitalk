/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nan_inf_80bit_darwin.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:39 by stanaka2          #+#    #+#             */
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
	if (my_double->significand == 0 && (my_double->sign || ctx->sign_flags))
		len++;
	if (ctx->width_flags != '-')
		ft_print_space_width(ctx, len);
	if (my_double->significand == 0)
		ft_print_sign(ctx, my_double->sign);
	ft_xprint_strn(ctx, special_case, ft_strlen(special_case));
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
