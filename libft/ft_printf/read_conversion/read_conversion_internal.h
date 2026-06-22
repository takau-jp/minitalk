/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conversion_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:20:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:36:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CONVERSION_INTERNAL_H
# define READ_CONVERSION_INTERNAL_H

# include <stdbool.h>

# define CONV "cspdiuxX%onfFeEgGaA"
# define FLAGS "-+ #0"
# define LENGTH "hljztL"

bool	pf_check_int_overflow(const char *format);
int		pf_precision_atoi(const char *format);

#endif
