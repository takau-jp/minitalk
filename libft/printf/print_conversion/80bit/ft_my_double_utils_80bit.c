/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_double_utils_80bit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:08:32 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:27:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_init_my_double_80bit(t_my_double *my_double)
{
	ft_bzero(my_double, sizeof(t_my_double));
	my_double->decimal_int = ft_calloc(PF_LDBL_INT, sizeof(uint8_t));
	if (!my_double->decimal_int)
		return (false);
	my_double->decimal_frac = ft_calloc(PF_LDBL_FRAC, sizeof(uint8_t));
	if (!my_double->decimal_frac)
	{
		free(my_double->decimal_int);
		return (false);
	}
	return (true);
}

void	ft_free_my_double_80bit(t_my_double *my_double)
{
	free(my_double->decimal_int);
	free(my_double->decimal_frac);
}
