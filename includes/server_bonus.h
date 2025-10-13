/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:25:15 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/13 22:02:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "libft.h"
# include "utf8_bonus.h"
# include <signal.h>

# define INITIAL 1
# define TIME_OUT 3
# define BUF_SIZE 1024
// BUF_CAPACITY = BUF_SIZE(1024) - BUF_UTF8_MAX_MARGIN(6) - NULL_TERMINATOR(1)
# define BUF_CAPACITY 1017

void		server_error(void);
void		print_server_pid(void);
uint8_t		receive_bit(int sig);
void		process_byte(unsigned char byte, size_t *buf_len);

#endif
