/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utf8_byte_sequence_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:07:31 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/24 17:15:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8_bonus.h"

bool	validate_utf8_leading_byte(t_utf8 *utf8);
bool	validate_utf8_trailing_byte(t_utf8 *utf8);

bool	validate_utf8_byte_sequence(unsigned char byte)
{
	static t_utf8	utf8;

	utf8.byte_sequences[utf8.len++] = byte;
	if (utf8.len == 1)
		return (validate_utf8_leading_byte(&utf8));
	else
		return (validate_utf8_trailing_byte(&utf8));
}

bool	validate_utf8_leading_byte(t_utf8 *utf8)
{
	if (!is_utf8_leading_byte(utf8->byte_sequences[0]))
	{
		utf8->len = 0;
		return (false);
	}
	utf8->expected_len = calc_utf8_expected_len(utf8->byte_sequences[0]);
	if (utf8->expected_len == 1)
		utf8->len = 0;
	else if (utf8->expected_len == 2 && !check_utf8_overlong_encoding(utf8))
	{
		utf8->len = 0;
		return (false);
	}
	else if (utf8->expected_len == 4 && !check_unicode_scalar_value(utf8))
	{
		utf8->len = 0;
		return (false);
	}
	return (true);
}

bool	validate_utf8_trailing_byte(t_utf8 *utf8)
{
	if (!is_utf8_trailing_byte(utf8->byte_sequences[utf8->len - 1]) \
		|| !check_utf8_overlong_encoding(utf8) \
		|| !check_unicode_scalar_value(utf8))
	{
		utf8->byte_sequences[0] = utf8->byte_sequences[utf8->len - 1];
		utf8->len = 1;
		validate_utf8_leading_byte(utf8);
		return (false);
	}
	if (utf8->len == utf8->expected_len)
	{
		utf8->len = 0;
	}
	return (true);
}
