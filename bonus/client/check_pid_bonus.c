/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:33:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/26 19:25:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

bool	check_pid(char *input)
{
	long	pid;
	int		sign;

	sign = 1;
	if (*input == '-')
	{
		input++;
		sign = -1;
	}
	pid = 0;
	if (*input == '\0')
		return (false);
	while (*input != '\0')
	{
		if (!ft_isdigit(*input) || (sign == 1 && pid > INT_MAX) \
			|| (sign == -1 && pid > (long)INT_MAX + 1))
			return (false);
		pid = pid * 10 + (*input - '0');
		input++;
	}
	pid *= sign;
	if (pid < -1 || pid == -1 || pid == 0 || pid == 1)
		return (false);
	return (true);
}
