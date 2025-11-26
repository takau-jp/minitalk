/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:10:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/20 17:00:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	process_byte(unsigned char byte, size_t *buf_len)
{
	static unsigned char	buf[BUF_SIZE];

	buf[(*buf_len)++] = byte;
	if (byte == '\0')
	{
		if (ft_putendl_fd_bytes((char *)buf, STDOUT_FILENO) == -1)
			server_error();
		*buf_len = 0;
		return ;
	}
	else
	{
		if (*buf_len == BUF_CAPACITY)
		{
			buf[*buf_len] = '\0';
			if (ft_putstr_fd_bytes((char *)buf, STDOUT_FILENO) == -1)
				server_error();
			*buf_len = 0;
		}
	}
}
