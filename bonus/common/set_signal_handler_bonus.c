/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:58:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/19 22:36:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

bool	set_signal_handler(struct sigaction *sa, int blocked_signums[], \
	void (*signal_handler)(int, siginfo_t *, void *), int handled_signums[])
{
	int	i;

	if (sigemptyset(&(sa->sa_mask)) == -1)
		return (false);
	i = 0;
	while (blocked_signums[i] != -1)
	{
		if (sigaddset(&(sa->sa_mask), blocked_signums[i]) == -1)
			return (false);
		i++;
	}
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = signal_handler;
	i = 0;
	while (handled_signums[i] != -1)
	{
		if (sigaction(handled_signums[i], sa, NULL) == -1)
			return (false);
		i++;
	}
	return (true);
}
