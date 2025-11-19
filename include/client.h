/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:31:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/08 16:00:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <signal.h>

# define ACK_RESPONSE 1
# define LAST_SAFE_WAIT 500

bool	check_pid(char *input);
void	client_error(void);
void	server_error(void);
void	server_connection_error(void);

#endif