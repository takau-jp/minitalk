/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:44:01 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	sender(pid_t pid, unsigned char *text);
void	backoff_wait_ack(void);
void	ack_handler(int sig, siginfo_t *info, void *ucontext);
void	nak_handler(int sig, siginfo_t *info, void *ucontext);

static volatile sig_atomic_t	g_server_info;

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	ack_sa;
	struct sigaction	nak_sa;

	if (argc != 3 || check_pid(argv[1]) == false)
		invalid_argument_error();
	if (!utf8_validation(argv[2]))
		ft_putendl_fd("[WARNING!!]Invalid UTF-8 byte sequence detected.", 2);
	pid = (pid_t)ft_atoi(argv[1]);
	if (set_signal_handler(&ack_sa, (int []){SIGUSR1, -1}, \
		ack_handler, (int []){SIGUSR1, -1}) == false)
		client_error();
	if (set_signal_handler(&nak_sa, (int []){SIGUSR1, SIGUSR2, -1}, \
		nak_handler, (int []){SIGUSR2, -1}) == false)
		client_error();
	sender(pid, (unsigned char *)argv[2]);
}

void	sender(pid_t pid, unsigned char *text)
{
	uint8_t	sending_bit;
	int		sig;

	while (true)
	{
		sending_bit = 8;
		while (sending_bit--)
		{
			g_server_info = pid;
			if (sending_bit == 0 && *text == '\0')
				usleep(LAST_SAFE_WAIT);
			if ((*text >> sending_bit) & 1)
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			if (kill(pid, sig) == -1)
				server_connection_error();
			backoff_wait_ack();
		}
		if (*text == '\0')
			break ;
		text++;
	}
}

void	backoff_wait_ack(void)
{
	int	wait_time;
	int	timeout;

	timeout = ACK_TIME_OUT;
	wait_time = 1;
	while (g_server_info != ACK_RESPONSE && timeout > 0)
	{
		usleep(wait_time);
		timeout -= wait_time;
		wait_time *= 2;
	}
	if (g_server_info != ACK_RESPONSE)
		server_connection_error();
}

void	ack_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_server_info == info->si_pid)
	{
		if (sig == SIGUSR1)
			g_server_info = ACK_RESPONSE;
	}
}

void	nak_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)sig;
	if (g_server_info == info->si_pid)
		server_error();
}
