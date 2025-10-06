/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:43:25 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 20:21:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd_bytes(char *s, int fd)
{
	size_t	len;
	size_t	chunk;
	ssize_t	write_res;
	ssize_t	written_bytes;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	written_bytes = 0;
	while (len)
	{
		chunk = WRITE_BLOCK_SIZE;
		if (len < WRITE_BLOCK_SIZE)
			chunk = len;
		write_res = write(fd, s + written_bytes, chunk);
		if (write_res <= 0)
			return (-1);
		written_bytes += write_res;
		len -= write_res;
	}
	write_res = write(fd, "\n", 1);
	if (write_res <= 0)
		return (-1);
	written_bytes += write_res;
	return (written_bytes);
}
