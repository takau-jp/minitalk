/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 00:47:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/24 13:56:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	ft_read_file(t_gnl_mem *mem, int fd);
static bool	ft_find_newline(t_gnl_mem *mem);
static char	*ft_get_line(t_gnl_mem *mem);
static void	ft_get_remainder_line(t_gnl_mem *mem);

char	*get_next_line(int fd)
{
	static t_gnl_mem	mem;
	char				*next_line;

	if (mem.len != 0)
	{
		mem.line = (char *)malloc(mem.len);
		if (!mem.line)
			return (ft_gnl_mem_reset(&mem));
		ft_memcpy(mem.line, mem.remainder_line, mem.len);
	}
	if (!ft_read_file(&mem, fd))
		return (ft_gnl_mem_reset(&mem));
	if (mem.eof && mem.len == 0)
		return (ft_gnl_mem_reset(&mem));
	next_line = ft_get_line(&mem);
	if (!next_line)
		return (ft_gnl_mem_reset(&mem));
	ft_get_remainder_line(&mem);
	return (next_line);
}

static bool	ft_read_file(t_gnl_mem *mem, int fd)
{
	char	*buf;
	ssize_t	res;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return (false);
	while (!ft_find_newline(mem) && !mem->eof)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == 0)
			mem->eof = true;
		if (res != -1)
			tmp = ft_gnl_mem_join(mem, buf, res);
		if (res == -1 || !tmp)
		{
			free(buf);
			return (false);
		}
		free(mem->line);
		mem->line = tmp;
		mem->len += res;
	}
	free(buf);
	return (true);
}

static bool	ft_find_newline(t_gnl_mem *mem)
{
	size_t	i;

	i = mem->newline_offset;
	while (i < mem->len)
	{
		if (mem->line[i] == '\0' || mem->line[i] == '\n')
		{
			if (i != 0 && mem->line[i] == '\0')
				mem->newline_offset = i - 1;
			else
				mem->newline_offset = i;
			mem->is_newline = true;
			return (true);
		}
		i++;
	}
	mem->newline_offset = i;
	mem->is_newline = false;
	return (false);
}

static char	*ft_get_line(t_gnl_mem *mem)
{
	char	*line;
	size_t	len;

	if (mem->eof && mem->is_newline == false)
		len = mem->len;
	else
		len = mem->newline_offset + 1;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, mem->line, len);
	line[len] = '\0';
	return (line);
}

static void	ft_get_remainder_line(t_gnl_mem *mem)
{
	size_t	remainder_len;

	if (mem->eof && mem->is_newline == false)
	{
		mem->len = 0;
		return ;
	}
	remainder_len = mem->len - mem->newline_offset - 1;
	ft_memcpy(mem->remainder_line, mem->line + mem->newline_offset + 1, \
			remainder_len);
	mem->len = remainder_len;
	mem->newline_offset = 0;
	free(mem->line);
	mem->line = NULL;
}
