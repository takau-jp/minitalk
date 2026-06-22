/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_conversion_darwin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:42:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 16:27:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "./read_conversion_internal.h"

static void	read_flags(const char **format, t_conv *conv);
static bool	read_width(\
				va_list *ap, const char **format, t_ctx *ctx, t_conv *conv);
static bool	read_precision(va_list *ap, const char **format, t_conv *conv);
static void	read_length(const char **format, t_conv *conv);

bool	pf_read_conversion(
	va_list *ap, const char **format, t_ctx *ctx, t_conv *conv)
{
	(*format)++;
	while (ft_strchr(FLAGS, **format) != NULL \
		|| ft_isdigit(**format) \
		|| **format == '*' \
		|| **format == '.' \
		|| ft_strchr(LENGTH, **format) != NULL)
	{
		read_flags(format, conv);
		if (!read_width(ap, format, ctx, conv))
		{
			ctx->has_error = true;
			return (false);
		}
		if (!read_precision(ap, format, conv))
		{
			ctx->has_error = true;
			return (false);
		}
		read_length(format, conv);
	}
	if (ft_strchr(CONV, **format) == NULL)
		return (false);
	conv->identifier = **format;
	(*format)++;
	return (true);
}

static void	read_flags(const char **format, t_conv *conv)
{
	while (ft_strchr(FLAGS, **format) != NULL)
	{
		if (**format == '#')
			conv->hash_flag = '#';
		else if (**format == '+' || **format == ' ')
		{
			if (conv->sign_flags != '+')
				conv->sign_flags = **format;
		}
		else if (**format == '-' || **format == '0')
		{
			if (conv->width_flags != '-')
				conv->width_flags = **format;
		}
		(*format)++;
	}
}

static bool	read_width(
	va_list *ap, const char **format, t_ctx *ctx, t_conv *conv)
{
	if (!(ft_isdigit(**format) || **format == '*'))
		return (true);
	if (ft_isdigit(**format))
	{
		if (pf_check_int_overflow(*format))
			return (false);
		conv->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		conv->width = va_arg(*ap, int);
		if (conv->width < 0 && conv->width != INT_MIN)
		{
			conv->width_flags = '-';
			conv->width *= -1;
		}
		if (conv->width < 0)
			return (false);
		(*format)++;
	}
	if (PRINTF_RESULT_LIMIT - ctx->count < (size_t)conv->width)
		return (false);
	return (true);
}

static bool	read_precision(va_list *ap, const char **format, t_conv *conv)
{
	if (**format == '.')
	{
		conv->has_prec = true;
		(*format)++;
		if (**format == '*')
		{
			conv->precision = va_arg(*ap, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			conv->precision = pf_precision_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		if (conv->precision < 0)
		{
			conv->has_prec = false;
			conv->precision = 0;
		}
	}
	return (true);
}

static void	read_length(const char **format, t_conv *conv)
{
	if (ft_strchr(LENGTH, **format) != NULL)
	{
		if (ft_strncmp(*format, "hh", 2) == 0)
			conv->length = LENGTH_HH;
		else if (**format == 'h')
			conv->length = LENGTH_H;
		else if (ft_strncmp(*format, "ll", 2) == 0)
			conv->length = LENGTH_LOWER_LL;
		else if (**format == 'l')
			conv->length = LENGTH_LOWER_L;
		else if (**format == 'L')
			conv->length = LENGTH_UPPER_L;
		else if (**format == 'j')
			conv->length = LENGTH_J;
		else if (**format == 'z')
			conv->length = LENGTH_Z;
		else if (**format == 't')
			conv->length = LENGTH_T;
		++(*format);
		if (conv->length == LENGTH_HH || conv->length == LENGTH_LOWER_LL)
			++(*format);
	}
	else
		conv->length = NO_LENGTH;
}
