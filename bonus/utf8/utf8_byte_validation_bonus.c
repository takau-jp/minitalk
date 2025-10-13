/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_byte_validation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:28:57 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/13 21:46:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8_bonus.h"

bool	is_utf8_leading_byte(unsigned char byte)
{
	if ((byte & 0b10000000) == 0b00000000)
		return (true);
	else if ((byte & 0b11100000) == 0b11000000)
		return (true);
	else if ((byte & 0b11110000) == 0b11100000)
		return (true);
	else if ((byte & 0b11111000) == 0b11110000)
		return (true);
	return (false);
}

bool	is_utf8_trailing_byte(unsigned char byte)
{
	return ((byte & 0b11000000) == 0b10000000);
}
