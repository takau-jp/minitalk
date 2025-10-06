/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_validate_and_append_byte_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:29:26 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/28 02:30:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

bool	utf8_validate_and_append_leading_byte(unsigned char *buf, \
			size_t *buf_len, unsigned char byte, t_utf8 *utf8);
bool	utf8_validate_and_append_continuation_byte(unsigned char *buf, \
			size_t *buf_len, unsigned char byte, t_utf8 *utf8);

bool	utf8_validate_and_append_byte(\
			unsigned char *buf, size_t *buf_len, unsigned char byte)
{
	static t_utf8	utf8;

	if (is_utf8_leading_byte(byte))
	{
		return (utf8_validate_and_append_leading_byte(\
			buf, buf_len, byte, &utf8));
	}
	else if (is_utf8_continuation_byte(byte))
	{
		return (utf8_validate_and_append_continuation_byte(\
			buf, buf_len, byte, &utf8));
	}
	else
	{
		append_utf8_replacement_character(buf, buf_len);
		utf8.len = 0;
		return (true);
	}
}

bool	utf8_validate_and_append_leading_byte(unsigned char *buf, \
			size_t *buf_len, unsigned char byte, t_utf8 *utf8)
{
	utf8->expected_len = calc_utf8_expected_len(byte);
	if (utf8->len != 0)
	{
		append_utf8_replacement_character(buf, buf_len);
		utf8->len = 0;
		if (utf8->expected_len == 1)
			buf[(*buf_len)++] = byte;
		else
			utf8->byte_sequences[utf8->len++] = byte;
		return (true);
	}
	if (utf8->expected_len == 1)
	{
		buf[(*buf_len)++] = byte;
		return (true);
	}
	else
	{
		utf8->byte_sequences[utf8->len++] = byte;
		return (false);
	}
}

bool	utf8_validate_and_append_continuation_byte(unsigned char *buf, \
			size_t *buf_len, unsigned char byte, t_utf8 *utf8)
{
	utf8->byte_sequences[utf8->len++] = byte;
	if (utf8->len != utf8->expected_len)
		return (false);
	else
	{
		if (!check_utf8_code_point(utf8))
			append_utf8_replacement_character(buf, buf_len);
		else
		{
			ft_memcpy(buf + *buf_len, utf8->byte_sequences, utf8->len);
			*buf_len += utf8->len;
		}
		utf8->len = 0;
		return (true);
	}
}
