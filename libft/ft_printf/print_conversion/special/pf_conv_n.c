/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:43:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 20:19:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

#include "ft_printf/ft_printf.h"

void	pf_conv_n(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	if (conv->length == LENGTH_HH)
		*(va_arg(*ap, signed char *)) = (signed char)ctx->count;
	else if (conv->length == LENGTH_H)
		*(va_arg(*ap, signed short int *)) = (signed short int)ctx->count;
	else if (conv->length == LENGTH_LOWER_L)
		*(va_arg(*ap, long int *)) = (long int)ctx->count;
	else if (conv->length == LENGTH_LOWER_LL)
		*(va_arg(*ap, long long int *)) = (long long int)ctx->count;
	else if (conv->length == LENGTH_J)
		*(va_arg(*ap, intmax_t *)) = (intmax_t)ctx->count;
	else if (conv->length == LENGTH_Z)
		*(va_arg(*ap, ssize_t *)) = (ssize_t)ctx->count;
	else if (conv->length == LENGTH_T)
		*(va_arg(*ap, ptrdiff_t *)) = (ptrdiff_t)ctx->count;
	else
		*(va_arg(*ap, int *)) = (int)ctx->count;
}
