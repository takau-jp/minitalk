/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:39:57 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/14 07:35:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTF8_BONUS_H
# define UTF8_BONUS_H

# include "libft.h"

typedef struct s_utf8
{
	unsigned char	byte_sequences[4];
	uint8_t			len;
	uint8_t			expected_len;
}	t_utf8;

bool		validate_utf8_byte_sequence(unsigned char byte);
bool		append_utf8_byte_sequence(\
				unsigned char *buf, size_t *buf_len, unsigned char byte);
uint8_t		calc_utf8_expected_len(unsigned char byte);
uint32_t	decode_utf8(t_utf8 *utf8);
void		append_utf8_replacement_character(\
				unsigned char *buf, size_t *buf_len);
bool		is_utf8_leading_byte(unsigned char byte);
bool		is_utf8_trailing_byte(unsigned char byte);
bool		check_utf8_overlong_encoding(t_utf8 *utf8);
bool		check_unicode_scalar_value(t_utf8 *utf8);
bool		is_noncharacter_codepoint(wchar_t code_point);

#endif
