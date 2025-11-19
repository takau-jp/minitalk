/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:24:56 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/13 21:46:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "libft.h"
# include "utf8_bonus.h"
# include <signal.h>

# define ACK_RESPONSE 1
# define LAST_SAFE_WAIT 500

bool	check_pid(char *input);
void	client_error(void);
void	server_error(void);
void	server_connection_error(void);
bool	utf8_validation(char *text);

#endif
