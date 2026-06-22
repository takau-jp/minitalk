/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:33:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:32:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTILS_INTERNAL_H
# define PRINT_UTILS_INTERNAL_H

# include <stddef.h>

# include "ft_printf/types.h"

# ifdef __APPLE__
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 16384
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE PAGE_SIZE
#  endif
#  ifndef PIPE_BUF
#   define PIPE_BUF 4096
#  endif
# else
#  ifndef PAGE_SIZE
#   define PAGE_SIZE 4096
#  endif
#  ifndef WRITE_BLOCK_SIZE
#   define WRITE_BLOCK_SIZE 16384
#  endif
#  ifndef PIPE_BUF
#   define PIPE_BUF 4096
#  endif
# endif

void	pf_print_repeated_char(t_ctx *ctx, char c, size_t count);

#endif
