/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nan_inf_binary64_darwin.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:39 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:04:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_print_nan_inf_binary64(t_dprintf_ctx *ctx, t_my_double *my_double)
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
		len += ft_strlen("-");
	if (ctx->width_flags != '-')
		ft_print_space_width(ctx, len);
	if (my_double->significand == 0)
		ft_print_sign(ctx, my_double->sign);
	ft_dprint_strn(ctx, special_case, ft_strlen(special_case));
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}

void	ft_print_nan_inf_hex_binary64(
			t_dprintf_ctx *ctx, t_my_double_hex *my_double_hex)
{
	char	*special_case;
	size_t	len;

	len = 3;
	if (my_double_hex->fraction == 0)
	{
		special_case = "inf";
		if (ctx->conv == 'A')
			special_case = "INF";
		if ((my_double_hex->sign || ctx->sign_flags))
			len += ft_strlen("-");
	}
	else
	{
		special_case = "nan";
		if (ctx->conv == 'A')
			special_case = "NAN";
	}
	if (ctx->width_flags != '-')
		ft_print_space_width(ctx, len);
	if (my_double_hex->fraction == 0)
		ft_print_sign(ctx, my_double_hex->sign);
	ft_dprint_strn(ctx, special_case, ft_strlen(special_case));
	if (ctx->width_flags == '-')
		ft_print_space_width(ctx, len);
}
