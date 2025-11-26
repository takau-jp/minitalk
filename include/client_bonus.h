/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:24:56 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/21 17:21:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "libft.h"
# include "utf8_bonus.h"
# include <signal.h>

# define ACK_RESPONSE -1
# define ACK_TIME_OUT 3000000 // 3,000,000μs = 3s
# define LAST_SAFE_WAIT 500

bool	check_pid(char *input);
bool	set_signal_handler(struct sigaction *sa, int blocked_signums[], \
	void (*signal_handler)(int, siginfo_t *, void *), int handled_signums[]);
void	invalid_argument_error(void);
void	client_error(void);
void	server_error(void);
void	server_connection_error(void);
bool	utf8_validation(char *text);

#endif
