/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:25:15 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/08 16:07:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "libft.h"
# include <signal.h>

# define INITIAL 1
# define TIME_OUT 3

typedef struct s_utf8
{
	unsigned char	byte_sequences[4];
	uint8_t			len;
	uint8_t			expected_len;
}	t_utf8;

void		server_error(void);
void		print_server_pid(void);
uint8_t		receive_bit(int sig);
void		process_byte(unsigned char byte, size_t *buf_len);
bool		utf8_validate_and_append_byte(\
				unsigned char *buf, size_t *buf_len, unsigned char byte);
bool		is_utf8_leading_byte(unsigned char byte);
bool		is_utf8_continuation_byte(unsigned char byte);
uint8_t		calc_utf8_expected_len(unsigned char byte);
bool		check_utf8_code_point(t_utf8 *utf8);
uint32_t	decode_utf8(t_utf8 *utf8);
void		append_utf8_replacement_character(\
				unsigned char *buf, size_t *buf_len);

#endif