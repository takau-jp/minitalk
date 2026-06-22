/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_internal.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:24:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 12:43:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_CONVERSION_INTERNAL_H
# define PRINT_CONVERSION_INTERNAL_H

# include <stdint.h>
# include <stddef.h>

size_t	pf_get_digits_base(uintmax_t num, size_t base_size);

#endif
