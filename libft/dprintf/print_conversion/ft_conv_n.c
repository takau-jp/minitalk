/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:59:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/30 14:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_conv_n(va_list *ap, t_dprintf_ctx *ctx)
{
	if (!ft_strcmp(ctx->length, "hh"))
		*(va_arg(*ap, signed char *)) = (signed char)ctx->res;
	else if (!ft_strcmp(ctx->length, "h"))
		*(va_arg(*ap, signed short int *)) = (signed short int)ctx->res;
	else if (!ft_strcmp(ctx->length, "l"))
		*(va_arg(*ap, long int *)) = (long int)ctx->res;
	else if (!ft_strcmp(ctx->length, "ll"))
		*(va_arg(*ap, long long int *)) = (long long int)ctx->res;
	else if (!ft_strcmp(ctx->length, "j"))
		*(va_arg(*ap, intmax_t *)) = (intmax_t)ctx->res;
	else if (!ft_strcmp(ctx->length, "z"))
		*(va_arg(*ap, ssize_t *)) = (ssize_t)ctx->res;
	else if (!ft_strcmp(ctx->length, "t"))
		*(va_arg(*ap, ptrdiff_t *)) = (ptrdiff_t)ctx->res;
	else
		*(va_arg(*ap, int *)) = (int)ctx->res;
}
