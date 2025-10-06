/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:18:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
