/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utf8_code_point_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:28:57 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/26 02:51:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

bool	is_utf8_invalid_code_point(uint32_t code_point);
bool	is_surrogates_code_point(uint32_t code_point);
bool	is_utf8_overlong_encoding(t_utf8 *utf8, uint32_t code_point);

bool	check_utf8_code_point(t_utf8 *utf8)
{
	uint32_t	code_point;

	code_point = decode_utf8(utf8);
	if (is_utf8_invalid_code_point(code_point))
		return (false);
	if (is_utf8_overlong_encoding(utf8, code_point))
		return (false);
	return (true);
}

bool	is_utf8_invalid_code_point(uint32_t code_point)
{
	if (is_surrogates_code_point(code_point))
		return (true);
	if (0x10FFFF < code_point)
		return (true);
	return (false);
}

bool	is_surrogates_code_point(uint32_t code_point)
{
	return (0xD800 <= code_point && code_point <= 0xDFFF);
}

bool	is_utf8_overlong_encoding(t_utf8 *utf8, uint32_t code_point)
{
	if (code_point <= 0x007F)
	{
		if (utf8->len != 1)
			return (true);
	}
	else if (0x0080 <= code_point && code_point <= 0x07FF)
	{
		if (utf8->len != 2)
			return (true);
	}
	else if (0x0800 <= code_point && code_point <= 0xFFFF)
	{
		if (utf8->len != 3)
			return (true);
	}
	else if (0x10000 <= code_point && code_point <= 0x10FFFF)
	{
		if (utf8->len != 4)
			return (true);
	}
	return (false);
}
