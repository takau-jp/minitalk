/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:33:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/24 13:06:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static bool	is_long_overflow(long num, int sign, int n);

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
	while (ft_isdigit(*input))
	{
		if (is_long_overflow(pid, sign, (*input - '0')))
			return (false);
		pid = pid * 10 + (*input - '0');
		input++;
	}
	if (*input != '\0')
		return (false);
	pid *= sign;
	if (pid < -1 || pid == -1 || pid == 0 || pid == 1)
		return (false);
	return (true);
}

static bool	is_long_overflow(long num, int sign, int n)
{
	long	limit;

	if (sign == 1)
		limit = LONG_MAX;
	else
		limit = LONG_MIN;
	if (num > LONG_MAX / 10
		|| (num == LONG_MAX / 10 && (int)(ft_abs_ulong(limit) % 10) < n))
		return (true);
	return (false);
}
