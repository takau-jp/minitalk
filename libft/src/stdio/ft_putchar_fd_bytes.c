/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:40:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/20 19:54:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_fd_bytes(char c, int fd)
{
	ssize_t	write_res;

	write_res = write(fd, &c, 1);
	if (write_res <= 0)
		return (-1);
	return (write_res);
}
