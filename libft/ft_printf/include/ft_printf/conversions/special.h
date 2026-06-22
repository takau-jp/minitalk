/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:11:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:32:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIAL_H
# define SPECIAL_H

# include <stdarg.h>

# include "ft_printf/types.h"

void	pf_conv_p(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_percent(t_ctx *ctx, t_conv *conv);
void	pf_conv_n(va_list *ap, t_ctx *ctx, t_conv *conv);

#endif
