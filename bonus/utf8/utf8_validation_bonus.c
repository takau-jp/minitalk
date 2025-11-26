/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:11:34 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/14 07:35:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

bool	utf8_validation(char *text)
{
	while (true)
	{
		if (validate_utf8_byte_sequence(*text) == false)
			return (false);
		if (*text == '\0')
			return (true);
		text++;
	}
}
