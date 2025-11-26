/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:30:35 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/20 17:04:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	invalid_argument_error(void)
{
	ft_putendl_fd(\
		"INVALID ARGUMENT ERROR!!! ./client PID(> 1) TEXT", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	client_error(void)
{
	ft_putendl_fd("CLIENT ERROR!!!", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	server_error(void)
{
	ft_putendl_fd("SERVER ERROR!!!", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	server_connection_error(void)
{
	ft_putendl_fd("SERVER CONNECTION ERROR!!!", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
