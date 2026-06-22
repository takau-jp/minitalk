/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:16:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:32:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>

# include "ft_printf/types.h"

# ifdef __APPLE__
#  define PRINTF_RESULT_LIMIT 2147483646
# else
#  define PRINTF_RESULT_LIMIT INT_MAX
# endif

# define PF_ERROR -1

enum e_dst_type
{
	PRINT_TO_FD,
	PRINT_TO_STR,
};

union u_dst
{
	int		fd;
	char	*str;
};

struct s_ctx
{
	enum e_dst_type	dst_type;
	union u_dst		dst;
	size_t			dst_size;
	size_t			count;
	bool			has_error;
};

enum e_length
{
	NO_LENGTH,
	LENGTH_HH,
	LENGTH_H,
	LENGTH_LOWER_LL,
	LENGTH_LOWER_L,
	LENGTH_UPPER_L,
	LENGTH_J,
	LENGTH_Z,
	LENGTH_T,
};

struct s_conversion
{
	char			identifier;
	char			hash_flag;
	char			sign_flags;
	char			width_flags;
	int				width;
	bool			has_prec;
	int				precision;
	enum e_length	length;
};

void	pf_xprintf(t_ctx *ctx, va_list *ap, const char *format);

#endif
