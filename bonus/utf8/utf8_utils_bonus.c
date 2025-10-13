/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:28:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/13 21:46:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8_bonus.h"

uint8_t	calc_utf8_expected_len(unsigned char byte)
{
	if ((byte & 0b10000000) == 0b00000000)
		return (1);
	else if ((byte & 0b11100000) == 0b11000000)
		return (2);
	else if ((byte & 0b11110000) == 0b11100000)
		return (3);
	else if ((byte & 0b11111000) == 0b11110000)
		return (4);
	else
		return (0);
}

uint32_t	decode_utf8(t_utf8 *utf8)
{
	uint32_t	code_point;

	if (utf8->len == 1)
		code_point = utf8->byte_sequences[0];
	else if (utf8->len == 2)
	{
		code_point = (uint32_t)(utf8->byte_sequences[0] & 0b00011111) << 6;
		code_point += (uint32_t)(utf8->byte_sequences[1] & 0b00111111);
	}
	else if (utf8->len == 3)
	{
		code_point = (uint32_t)(utf8->byte_sequences[0] & 0b00001111) << 12;
		code_point += (uint32_t)(utf8->byte_sequences[1] & 0b00111111) << 6;
		code_point += (uint32_t)(utf8->byte_sequences[2] & 0b00111111);
	}
	else
	{
		code_point = (uint32_t)(utf8->byte_sequences[0] & 0b00000111) << 18;
		code_point += (uint32_t)(utf8->byte_sequences[1] & 0b00111111) << 12;
		code_point += (uint32_t)(utf8->byte_sequences[2] & 0b00111111) << 6;
		code_point += (uint32_t)(utf8->byte_sequences[3] & 0b00111111);
	}
	return (code_point);
}

void	append_utf8_replacement_character(unsigned char *buf, size_t *buf_len)
{
	buf[(*buf_len)++] = 0b11101111;
	buf[(*buf_len)++] = 0b10111111;
	buf[(*buf_len)++] = 0b10111101;
}
