/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_byte_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:10:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/14 07:35:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	process_byte(unsigned char byte, size_t *buf_len)
{
	static unsigned char	buf[BUF_SIZE];
	bool					buf_appended;

	buf_appended = append_utf8_byte_sequence(buf, buf_len, byte);
	if (buf_appended == true)
	{
		if (byte == '\0')
		{
			if (ft_putendl_fd_bytes((char *)buf, 1) == -1)
				server_error();
			*buf_len = 0;
			return ;
		}
		else
		{
			if (*buf_len >= BUF_CAPACITY)
			{
				buf[*buf_len] = '\0';
				if (ft_putstr_fd_bytes((char *)buf, 1) == -1)
					server_error();
				*buf_len = 0;
			}
		}
	}
}
