/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:38:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/07/21 18:59:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

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

typedef struct s_gnl_mem
{
	char	*line;
	char	remainder_line[BUFFER_SIZE];
	size_t	len;
	bool	eof;
	bool	is_newline;
	size_t	newline_offset;
}	t_gnl_mem;

char	*get_next_line(int fd);
char	*ft_gnl_mem_join(t_gnl_mem *mem, char *buf, size_t res);
void	*ft_gnl_mem_reset(t_gnl_mem *mem);

#endif
