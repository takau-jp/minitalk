/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:24:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:32:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_CONVERSION_H
# define PRINT_CONVERSION_H

# include <stdarg.h>

# include "ft_printf/types.h"

void	pf_print_conversion(va_list *ap, t_ctx *ctx, t_conv *conv);

#endif
