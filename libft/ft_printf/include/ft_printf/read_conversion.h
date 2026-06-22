/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conversion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:27:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:32:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CONVERSION_H
# define READ_CONVERSION_H

# include <stdarg.h>
# include <stdbool.h>

# include "ft_printf/types.h"

bool	pf_read_conversion(\
			va_list *ap, const char **format, t_ctx *ctx, t_conv *conv);

#endif
