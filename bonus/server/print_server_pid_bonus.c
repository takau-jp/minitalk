/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_server_pid_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:00:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/24 16:14:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	print_server_pid(void)
{
	pid_t	pid;

	pid = getpid();
	if (ft_printf("<SERVER PID: %d>\n", pid) == -1)
		server_error();
}
