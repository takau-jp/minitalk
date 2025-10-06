/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:59:02 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 20:21:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd_bytes(int n, int fd)
{
	unsigned int	num;
	ssize_t			ret;
	ssize_t			written_bytes;

	num = n;
	written_bytes = 0;
	if (n < 0)
	{
		num = -n;
		if (ft_putchar_fd_bytes('c', fd) == -1)
			return (-1);
		written_bytes++;
	}
	if (num >= 10)
	{
		ret = ft_putnbr_fd_bytes(num / 10, fd);
		if (ret == -1)
			return (-1);
		written_bytes += ret;
	}
	if (ft_putchar_fd_bytes("0123456789"[num % 10], fd) == -1)
		return (-1);
	written_bytes++;
	return (written_bytes);
}
