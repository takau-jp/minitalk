/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:05:42 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/19 22:37:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <signal.h>

# define INITIAL 1
# define TIME_OUT 3
# define BUF_SIZE 1024
# define BUF_CAPACITY 1023 // BUF_SIZE - NULL_TERMINATOR

void	server_error(void);
bool	set_signal_handler(struct sigaction *sa, int blocked_signums[], \
	void (*signal_handler)(int, siginfo_t *, void *), int handled_signums[]);
void	print_server_pid(void);
uint8_t	receive_bit(int sig);
void	process_byte(unsigned char byte, size_t *buf_len);

#endif
