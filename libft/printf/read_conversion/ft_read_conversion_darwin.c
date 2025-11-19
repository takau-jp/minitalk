/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_conversion_darwin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:42:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_read_flags(const char **format, t_printf_ctx *ctx);
static bool	ft_read_width(va_list *ap,
				const char **format, t_printf_ctx *ctx);
static bool	ft_read_precision(va_list *ap,
				const char **format, t_printf_ctx *ctx);
static void	ft_read_length(const char **format, t_printf_ctx *ctx);

bool	ft_read_conversion(va_list *ap, const char **format, t_printf_ctx *ctx)
{
	(*format)++;
	while (ft_strchr(PF_FLAGS, **format) || ft_isdigit(**format)
		|| **format == '*' || **format == '.' || ft_strchr(PF_LENGTH, **format))
	{
		ft_read_flags(format, ctx);
		if (!ft_read_width(ap, format, ctx))
		{
			ctx->res = -1;
			return (false);
		}
		if (!ft_read_precision(ap, format, ctx))
		{
			ctx->res = -1;
			return (false);
		}
		ft_read_length(format, ctx);
	}
	if (!ft_strchr(PF_CONV, **format))
		return (false);
	ctx->conv = **format;
	(*format)++;
	return (true);
}

static void	ft_read_flags(const char **format, t_printf_ctx *ctx)
{
	while (ft_strchr(PF_FLAGS, **format))
	{
		if (**format == '#')
			ctx->hash_flag = '#';
		else if (**format == '+' || **format == ' ')
		{
			if (ctx->sign_flags != '+')
				ctx->sign_flags = **format;
		}
		else if (**format == '-' || **format == '0')
		{
			if (ctx->width_flags != '-')
				ctx->width_flags = **format;
		}
		(*format)++;
	}
}

static bool	ft_read_width(va_list *ap,
				const char **format, t_printf_ctx *ctx)
{
	if (!(ft_isdigit(**format) || **format == '*'))
		return (true);
	if (ft_isdigit(**format))
	{
		if (ft_check_int_overflow(*format))
			return (false);
		ctx->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		ctx->width = va_arg(*ap, int);
		if (ctx->width < 0)
		{
			ctx->width_flags = '-';
			ctx->width *= -1;
			if (ctx->width < 0)
				return (false);
		}
		(*format)++;
	}
	if (PRINTF_RESULT_LIMIT - ctx->res < ctx->width)
		return (false);
	return (true);
}

static bool	ft_read_precision(va_list *ap,
				const char **format, t_printf_ctx *ctx)
{
	if (**format == '.')
	{
		ctx->has_prec = true;
		(*format)++;
		if (**format == '*')
		{
			ctx->precision = va_arg(*ap, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			ctx->precision = ft_atoi_precision(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		if (ctx->precision < 0)
		{
			ctx->has_prec = false;
			ctx->precision = 0;
		}
	}
	return (true);
}

static void	ft_read_length(const char **format, t_printf_ctx *ctx)
{
	if (**format == 'h' || **format == 'l')
	{
		ctx->length[0] = **format;
		ctx->length[1] = '\0';
		(*format)++;
		if (**format == ctx->length[0])
		{
			ctx->length[1] = **format;
			ctx->length[2] = '\0';
			(*format)++;
		}
	}
	else if (ft_strchr(PF_LENGTH, **format))
	{
		ctx->length[0] = **format;
		ctx->length[1] = '\0';
		(*format)++;
	}
}
