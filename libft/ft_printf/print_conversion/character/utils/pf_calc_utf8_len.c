/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_utf8_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:40:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:52:42 by stanaka2         ###   ########.fr       */
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
	else if (0x10000 <= wc && wc <= 0x1FFFFF)
		return (4);
	else if (0x200000 <= wc && wc <= 0x3FFFFFF)
		return (5);
	else if (0x4000000 <= wc && wc <= 0x7FFFFFFF)
		return (6);
	else
		return (0);
}
