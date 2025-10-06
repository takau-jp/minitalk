/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:05:42 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/08 16:07:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <signal.h>

# define INITIAL 1
# define TIME_OUT 3

void	server_error(void);
void	print_server_pid(void);
uint8_t	receive_bit(int sig);
void	process_byte(unsigned char byte, int *buf_len);

#endif