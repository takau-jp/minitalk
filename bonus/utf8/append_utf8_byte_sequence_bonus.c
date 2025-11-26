/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_utf8_byte_sequence_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:29:26 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/24 16:20:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8_bonus.h"

void	append_utf8_leading_byte(
			unsigned char *buf, size_t *buf_len, t_utf8 *utf8);
void	append_utf8_trailing_byte(
			unsigned char *buf, size_t *buf_len, t_utf8 *utf8);

bool	append_utf8_byte_sequence(
			unsigned char *buf, size_t *buf_len, unsigned char byte)
{
	static t_utf8	utf8;
	const size_t	original_buf_len = *buf_len;

	utf8.byte_sequences[utf8.len++] = byte;
	if (utf8.len == 1)
		append_utf8_leading_byte(buf, buf_len, &utf8);
	else
		append_utf8_trailing_byte(buf, buf_len, &utf8);
	return (*buf_len != original_buf_len);
}

void	append_utf8_leading_byte(
			unsigned char *buf, size_t *buf_len, t_utf8 *utf8)
{
	if (!is_utf8_leading_byte(utf8->byte_sequences[0]))
	{
		append_utf8_replacement_character(buf, buf_len);
		utf8->len = 0;
		return ;
	}
	utf8->expected_len = calc_utf8_expected_len(utf8->byte_sequences[0]);
	if (utf8->expected_len == 1)
	{
		buf[(*buf_len)++] = utf8->byte_sequences[0];
		utf8->len = 0;
	}
	else if (utf8->expected_len == 2 && !check_utf8_overlong_encoding(utf8))
	{
		append_utf8_replacement_character(buf, buf_len);
		utf8->len = 0;
	}
	else if (utf8->expected_len == 4 && !check_unicode_scalar_value(utf8))
	{
		append_utf8_replacement_character(buf, buf_len);
		utf8->len = 0;
	}
}

void	append_utf8_trailing_byte(
			unsigned char *buf, size_t *buf_len, t_utf8 *utf8)
{
	if (!is_utf8_trailing_byte(utf8->byte_sequences[utf8->len - 1]) \
		|| !check_utf8_overlong_encoding(utf8) \
		|| !check_unicode_scalar_value(utf8))
	{
		append_utf8_replacement_character(buf, buf_len);
		utf8->byte_sequences[0] = utf8->byte_sequences[utf8->len - 1];
		utf8->len = 1;
		append_utf8_leading_byte(buf, buf_len, utf8);
		return ;
	}
	if (utf8->len == utf8->expected_len)
	{
		if (is_noncharacter_codepoint(decode_utf8(utf8)))
		{
			append_utf8_replacement_character(buf, buf_len);
			utf8->len = 0;
			return ;
		}
		ft_memcpy(buf + *buf_len, utf8->byte_sequences, utf8->len);
		*buf_len += utf8->len;
		utf8->len = 0;
	}
}
