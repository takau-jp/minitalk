/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:43:58 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/24 16:14:23 by stanaka2         ###   ########.fr       */
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

	g_client_pid = INITIAL;
	print_server_pid();
	if (set_signal_handler(&sa, (int []){SIGUSR1, SIGUSR2, -1}, \
			receiver, (int []){SIGUSR1, SIGUSR2, -1}) == false)
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
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	byte = (byte << 1) | receive_bit(sig);
	bit_count++;
	if (bit_count == 8)
	{
		process_byte(byte, &buf_len);
		bit_count = 0;
	}
	if (kill(g_client_pid, SIGUSR1) == -1)
		client_connection_error();
	if (bit_count == 0 && byte == '\0')
		g_client_pid = INITIAL;
}

void	init_for_new_client(uint8_t *bit_count, size_t *buf_len, pid_t pid)
{
	*bit_count = 0;
	*buf_len = 0;
	g_client_pid = pid;
	if (ft_putstr_fd_bytes("<CLIENT PID: ", STDOUT_FILENO) == -1)
		server_error();
	if (ft_putnbr_fd_bytes(g_client_pid, STDOUT_FILENO) == -1)
		server_error();
	if (ft_putchar_fd_bytes('>', STDOUT_FILENO) == -1)
		server_error();
}

void	server_error(void)
{
	ft_putendl_fd("SERVER ERROR!!!", STDERR_FILENO);
	if (g_client_pid != INITIAL)
		kill(g_client_pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

void	client_connection_error(void)
{
	g_client_pid = INITIAL;
	if (ft_putendl_fd_bytes(\
		"\nCLIENT CONNECTION ERROR!!!", STDERR_FILENO) == -1)
		server_error();
}
