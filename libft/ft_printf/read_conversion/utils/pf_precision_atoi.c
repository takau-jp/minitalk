/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:18:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:21:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	pf_precision_atoi(const char *format)
{
	int	num;

	num = 0;
	while (ft_isdigit(*format))
	{
		num = num * 10 + (*format - '0');
		format++;
	}
	return (num);
}
