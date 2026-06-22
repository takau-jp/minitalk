/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:16:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 16:48:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATING_POINT_H
# define FLOATING_POINT_H

# include <stdarg.h>

# include "ft_printf/types.h"

void	pf_conv_a_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_a_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_e_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_e_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_f_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_f_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_g_binary64(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_g_binary80(va_list *ap, t_ctx *ctx, t_conv *conv);

#endif
