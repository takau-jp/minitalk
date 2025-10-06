/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:39:49 by stanaka2          #+#    #+#             */
/*   Updated: 2025/07/21 19:00:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_mem_join(t_gnl_mem *mem, char *buf, size_t res)
{
	char	*joined_line;

	if (SIZE_MAX - mem->len < res)
		return (NULL);
	joined_line = (char *)malloc(mem->len + res);
	if (!joined_line)
		return (NULL);
	ft_memcpy(joined_line, mem->line, mem->len);
	ft_memcpy(joined_line + mem->len, buf, res);
	return (joined_line);
}

void	*ft_gnl_mem_reset(t_gnl_mem *mem)
{
	if (mem->line)
		free(mem->line);
	mem->line = NULL;
	ft_bzero(mem->remainder_line, BUFFER_SIZE);
	mem->len = 0;
	mem->eof = false;
	mem->newline_offset = 0;
	mem->is_newline = false;
	return (NULL);
}
