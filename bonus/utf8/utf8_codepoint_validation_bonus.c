/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_codepoint_validation_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:03:22 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/13 21:49:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8_bonus.h"

bool	is_surrogate_codepoint(t_utf8 *utf8);
bool	is_over_0x10ffff_codepoint(t_utf8 *utf8);

bool	check_utf8_overlong_encoding(t_utf8 *utf8)
{
	if (utf8->len == 1 && utf8->expected_len == 2)
	{
		if (utf8->byte_sequences[0] < 0b11000010)
			return (false);
	}
	else if (utf8->len == 2)
	{
		if (utf8->expected_len == 3)
		{
			if (utf8->byte_sequences[0] == 0b11100000 \
				&& utf8->byte_sequences[1] < 0b10100000)
				return (false);
		}
		else if (utf8->expected_len == 4)
		{
			if (utf8->byte_sequences[0] == 0b11110000 \
				&& utf8->byte_sequences[1] < 0b10010000)
				return (false);
		}
	}
	return (true);
}

bool	check_unicode_scalar_value(t_utf8 *utf8)
{
	if (is_surrogate_codepoint(utf8))
		return (false);
	if (is_over_0x10ffff_codepoint(utf8))
		return (false);
	return (true);
}

bool	is_surrogate_codepoint(t_utf8 *utf8)
{
	if (utf8->len == 2 && utf8->expected_len == 3)
	{
		if (utf8->byte_sequences[0] == 0b11101101 \
			&& utf8->byte_sequences[1] >= 0b10100000)
			return (true);
	}
	return (false);
}

bool	is_over_0x10ffff_codepoint(t_utf8 *utf8)
{
	if (utf8->len == 2 && utf8->expected_len == 4)
	{
		if (utf8->byte_sequences[0] == 0b11110100 \
			&& utf8->byte_sequences[1] >= 0b10010000)
			return (true);
	}
	return (false);
}

bool	is_noncharacter_codepoint(wchar_t code_point)
{
	if (code_point >= 0xFDD0 && code_point <= 0xFDEF)
		return (true);
	if ((code_point & 0xFFFE) == 0xFFFE && code_point <= 0x10FFFF)
		return (true);
	return (false);
}
