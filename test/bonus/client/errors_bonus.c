/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:30:35 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/24 14:28:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	client_error(void)
{
	ft_putendl_fd("CLIENT ERROR!!!", 2);
	exit(1);
}

void	server_error(void)
{
	ft_putendl_fd("SERVER ERROR!!!", 2);
	exit(1);
}

void	server_connection_error(void)
{
	ft_putendl_fd("SERVER CONNECTION ERROR!!!", 2);
	exit(1);
}
