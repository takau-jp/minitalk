/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:44:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:25:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_INTERNAL_H
# define CHARACTER_INTERNAL_H

# include <stdbool.h>
# include <stddef.h>
# include <wchar.h>

# include "ft_printf/types.h"

# ifdef __APPLE__
// REC2279
#  define UTF8_SIZE 6
# else
// REC3629
#  define UTF8_SIZE 4
# endif

// UTF-8 byte layout: *_MASK keeps the payload bits, *_MARKER sets the prefix
# define UTF8_CONT_MASK    0x3F /* 0b00111111 */
# define UTF8_CONT_MARKER  0x80 /* 0b10xxxxxx */
# define UTF8_LEAD1_MASK   0x7F /* 0b01111111 */
# define UTF8_LEAD1_MARKER 0x00 /* 0b0xxxxxxx */
# define UTF8_LEAD2_MASK   0x1F /* 0b00011111 */
# define UTF8_LEAD2_MARKER 0xC0 /* 0b110xxxxx */
# define UTF8_LEAD3_MASK   0x0F /* 0b00001111 */
# define UTF8_LEAD3_MARKER 0xE0 /* 0b1110xxxx */
# define UTF8_LEAD4_MASK   0x07 /* 0b00000111 */
# define UTF8_LEAD4_MARKER 0xF0 /* 0b11110xxx */
# define UTF8_LEAD5_MASK   0x03 /* 0b00000011 */
# define UTF8_LEAD5_MARKER 0xF8 /* 0b111110xx */
# define UTF8_LEAD6_MASK   0x01 /* 0b00000001 */
# define UTF8_LEAD6_MARKER 0xFC /* 0b1111110x */
// leading-byte test: a continuation byte is the only one matching 0b10xxxxxx
# define UTF8_TOP2_MASK    0xC0 /* 0b11000000 */

void	pf_print_null(t_ctx *ctx, t_conv *conv);
bool	pf_validate_codepoint(wchar_t wc);
size_t	pf_calc_utf8_len(wchar_t wc);
void	pf_encode_utf8(wchar_t wc, unsigned char *utf8);

#endif
