/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:07:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:32:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <stdarg.h>

# include "ft_printf/types.h"

void	pf_conv_c(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_s(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_lc(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_ls(va_list *ap, t_ctx *ctx, t_conv *conv);

#endif
