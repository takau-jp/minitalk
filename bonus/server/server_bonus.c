/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:43:58 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/08 16:10:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	receiver(int sig, siginfo_t *info, void *ucontext);
void	init_for_new_client(uint8_t *bit_count, size_t *buf_len, pid_t pid);
void	client_connection_error(void);

static volatile sig_atomic_t	g_client_pid;

int	main(void)
{
	struct sigaction	sa;

	print_server_pid();
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receiver;
	g_client_pid = INITIAL;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		server_error();
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		server_error();
	while (true)
	{
		if (g_client_pid != INITIAL)
		{
			if (sleep(TIME_OUT + 1) == 0)
				client_connection_error();
		}
		else
			pause();
	}
}

void	receiver(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static uint8_t			bit_count;
	static size_t			buf_len;

	(void)ucontext;
	if (g_client_pid == INITIAL)
		init_for_new_client(&bit_count, &buf_len, info->si_pid);
	else if (g_client_pid != info->si_pid)
		return ;
	byte = (byte << 1) | receive_bit(sig);
	bit_count++;
	if (bit_count == 8)
	{
		process_byte(byte, &buf_len);
		bit_count = 0;
		if (byte == '\0')
		{
			if (kill(g_client_pid, SIGUSR1) == -1)
				client_connection_error();
			g_client_pid = INITIAL;
			return ;
		}
	}
	if (kill(g_client_pid, SIGUSR1) == -1)
		client_connection_error();
}

void	init_for_new_client(uint8_t *bit_count, size_t *buf_len, pid_t pid)
{
	*bit_count = 0;
	*buf_len = 0;
	g_client_pid = pid;
	if (ft_putstr_fd_bytes("<CLIENT PID: ", 1) == -1)
		server_error();
	if (ft_putnbr_fd_bytes(g_client_pid, 1) == -1)
		server_error();
	if (ft_putchar_fd_bytes('>', 1) == -1)
		server_error();
}

void	server_error(void)
{
	ft_putendl_fd("SERVER ERROR!!!", 2);
	if (g_client_pid != INITIAL)
		kill(g_client_pid, SIGUSR2);
	exit(1);
}

void	client_connection_error(void)
{
	g_client_pid = INITIAL;
	if (ft_putendl_fd_bytes("\nCLIENT CONNECTION ERROR!!!", 2) == -1)
		server_error();
}
