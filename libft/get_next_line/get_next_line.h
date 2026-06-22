/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:40:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:22:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif

# ifdef __APPLE__
#  ifndef READ_LIMIT_SIZE
#   define READ_LIMIT_SIZE SSIZE_MAX
#  endif
# else
#  ifndef READ_LIMIT_SIZE
#   define READ_LIMIT_SIZE 0x7ffff000
#  endif
# endif

# if BUFFER_SIZE <= 0
#  error "INVALID BUFFER_SIZE ERROR"
# elif BUFFER_SIZE > READ_LIMIT_SIZE
#  error "INVALID BUFFER_SIZE ERROR"
# endif

typedef struct s_buf
{
	char	data[BUFFER_SIZE];
	ssize_t	read_bytes;
	ssize_t	used_bytes;
}	t_buf;

typedef struct s_line
{
	char	*data;
	size_t	len;
	size_t	allocated_size;
}	t_line;

#endif
