/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_inf_darwin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:25:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:33:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"
#include "../floating_point_internal.h"

void	pf_print_inf(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	char	*special_case;
	size_t	len;

	special_case = "inf";
	if (ft_strchr("FEGA", conv->identifier) != NULL)
		special_case = "INF";
	len = ft_strlen(special_case);
	if (fp->sign || conv->sign_flags != '\0')
		len += ft_strlen("-");
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_sign(ctx, conv, fp->sign);
	pf_print_strn(ctx, special_case, ft_strlen(special_case));
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}
