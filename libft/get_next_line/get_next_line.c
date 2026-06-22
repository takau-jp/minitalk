/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 00:47:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:03:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "./get_next_line.h"

static bool	read_file(int fd, t_buf *buf, t_line *line);
static bool	append_to_line(t_line *line, char c);

char	*get_next_line(int fd)
{
	static t_buf	buf;
	t_line			line;

	line.data = NULL;
	line.len = 0;
	line.allocated_size = 0;
	if (!read_file(fd, &buf, &line))
	{
		buf.read_bytes = 0;
		buf.used_bytes = 0;
		free(line.data);
		return (NULL);
	}
	return (line.data);
}

static bool	read_file(int fd, t_buf *buf, t_line *line)
{
	while (true)
	{
		if (buf->used_bytes == buf->read_bytes)
		{
			buf->used_bytes = 0;
			buf->read_bytes = read(fd, buf->data, BUFFER_SIZE);
			if (buf->read_bytes < 0)
				return (false);
			else if (buf->read_bytes == 0)
				return (true);
		}
		if (!append_to_line(line, buf->data[buf->used_bytes]))
			return (false);
		if (buf->data[buf->used_bytes] == '\n' \
			|| buf->data[buf->used_bytes] == '\0')
		{
			++(buf->used_bytes);
			return (true);
		}
		++(buf->used_bytes);
	}
}

static bool	append_to_line(t_line *line, char c)
{
	if (line->allocated_size != 0 && c == '\0')
		return (true);
	if (line->allocated_size == 0 \
		|| line->len + 1 == line->allocated_size)
	{
		if (line->allocated_size == 0 && c == '\0')
			line->allocated_size = 1;
		else if (line->allocated_size == 0)
			line->allocated_size = 2;
		else if (line->allocated_size < 1024)
			line->allocated_size = line->allocated_size * 2;
		else
			line->allocated_size = line->allocated_size + 1024;
		line->data = ft_reallocf(\
			line->data, line->len, line->allocated_size);
		if (line->data == NULL)
			return (false);
	}
	if (c != '\0')
		line->data[line->len++] = c;
	line->data[line->len] = '\0';
	return (true);
}
