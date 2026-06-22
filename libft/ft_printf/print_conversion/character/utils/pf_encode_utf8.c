/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_encode_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:16:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 14:13:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "../character_internal.h"

static void				encode_utf8_0x0_0x1fffff(\
							unsigned char *utf8, wchar_t wc);
static void				encode_utf8_0x200000_0x7fffffff(\
							unsigned char *utf8, wchar_t wc);
static unsigned char	encode_utf8_byte(wchar_t bits, int mask, int marker);

void	pf_encode_utf8(wchar_t wc, unsigned char *utf8)
{
	if (0x0 <= wc && wc <= 0x1FFFFF)
		encode_utf8_0x0_0x1fffff(utf8, wc);
	else if (0x200000 <= wc && wc <= 0x7FFFFFFF)
		encode_utf8_0x200000_0x7fffffff(utf8, wc);
}

static void	encode_utf8_0x0_0x1fffff(unsigned char *utf8, wchar_t wc)
{
	if (0x0000 <= wc && wc <= 0x007F)
	{
		utf8[0] = encode_utf8_byte(wc, UTF8_LEAD1_MASK, UTF8_LEAD1_MARKER);
	}
	else if (0x0080 <= wc && wc <= 0x07FF)
	{
		utf8[0] = encode_utf8_byte(wc >> 6, UTF8_LEAD2_MASK, UTF8_LEAD2_MARKER);
		utf8[1] = encode_utf8_byte(wc, UTF8_CONT_MASK, UTF8_CONT_MARKER);
	}
	else if (0x0800 <= wc && wc <= 0xFFFF)
	{
		utf8[0] \
			= encode_utf8_byte(wc >> 12, UTF8_LEAD3_MASK, UTF8_LEAD3_MARKER);
		utf8[1] = encode_utf8_byte(wc >> 6, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[2] = encode_utf8_byte(wc, UTF8_CONT_MASK, UTF8_CONT_MARKER);
	}
	else if (0x10000 <= wc && wc <= 0x1FFFFF)
	{
		utf8[0] \
			= encode_utf8_byte(wc >> 18, UTF8_LEAD4_MASK, UTF8_LEAD4_MARKER);
		utf8[1] = encode_utf8_byte(wc >> 12, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[2] = encode_utf8_byte(wc >> 6, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[3] = encode_utf8_byte(wc, UTF8_CONT_MASK, UTF8_CONT_MARKER);
	}
}

static void	encode_utf8_0x200000_0x7fffffff(unsigned char *utf8, wchar_t wc)
{
	if (0x200000 <= wc && wc <= 0x3FFFFFF)
	{
		utf8[0] \
			= encode_utf8_byte(wc >> 24, UTF8_LEAD5_MASK, UTF8_LEAD5_MARKER);
		utf8[1] = encode_utf8_byte(wc >> 18, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[2] = encode_utf8_byte(wc >> 12, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[3] = encode_utf8_byte(wc >> 6, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[4] = encode_utf8_byte(wc, UTF8_CONT_MASK, UTF8_CONT_MARKER);
	}
	else if (0x4000000 <= wc && wc <= 0x7FFFFFFF)
	{
		utf8[0] \
			= encode_utf8_byte(wc >> 30, UTF8_LEAD6_MASK, UTF8_LEAD6_MARKER);
		utf8[1] = encode_utf8_byte(wc >> 24, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[2] = encode_utf8_byte(wc >> 18, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[3] = encode_utf8_byte(wc >> 12, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[4] = encode_utf8_byte(wc >> 6, UTF8_CONT_MASK, UTF8_CONT_MARKER);
		utf8[5] = encode_utf8_byte(wc, UTF8_CONT_MASK, UTF8_CONT_MARKER);
	}
}

static unsigned char	encode_utf8_byte(wchar_t bits, int mask, int marker)
{
	return ((unsigned char)((bits & mask) | marker));
}
