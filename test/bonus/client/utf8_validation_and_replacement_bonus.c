/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_validation_and_replacement_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:11:34 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/28 02:28:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

unsigned char	*utf8_validation_and_replacement(char *text)
{
	size_t			reading_byte;
	unsigned char	*buf;
	size_t			buf_len;

	buf = (unsigned char *)malloc(\
		sizeof(unsigned char) * ft_strlen(text) * 3 + 1);
	if (buf == NULL)
		client_error();
	reading_byte = 0;
	buf_len = 0;
	while (true)
	{
		utf8_validate_and_append_byte(\
			buf, &buf_len, (unsigned char)text[reading_byte]);
		if (text[reading_byte] == '\0')
			break ;
		reading_byte++;
	}
	return ((unsigned char *)buf);
}
