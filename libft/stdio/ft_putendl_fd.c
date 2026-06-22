/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:07:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:08:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"
#include "./ft_stdio_internal.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	size_t	chunk;
	ssize_t	write_res;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len)
	{
		chunk = WRITE_BLOCK_SIZE;
		if (len < WRITE_BLOCK_SIZE)
			chunk = len;
		write_res = write(fd, s, chunk);
		if (write_res <= 0)
			return ;
		s += write_res;
		len -= write_res;
	}
	write(fd, "\n", 1);
}
