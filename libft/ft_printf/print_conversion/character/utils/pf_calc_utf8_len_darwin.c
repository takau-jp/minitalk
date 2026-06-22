/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_utf8_len_darwin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:40:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:52:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <wchar.h>

size_t	pf_calc_utf8_len(wchar_t wc)
{
	if (0x0000 <= wc && wc <= 0x007F)
		return (1);
	else if (0x0080 <= wc && wc <= 0x07FF)
		return (2);
	else if (0x0800 <= wc && wc <= 0xFFFF)
		return (3);
	else if (0x10000 <= wc && wc <= 0x10FFFF)
		return (4);
	else
		return (0);
}
