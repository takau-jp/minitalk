/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_bit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:33:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/08 15:55:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

uint8_t	receive_bit(int sig)
{
	if (sig == SIGUSR1)
		return (1);
	else
		return (0);
}
