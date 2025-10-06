/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_server_pid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:00:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/24 14:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_server_pid(void)
{
	pid_t	pid;

	pid = getpid();
	if (ft_printf("<SERVER PID: %d>\n", pid) == -1)
		server_error();
}
