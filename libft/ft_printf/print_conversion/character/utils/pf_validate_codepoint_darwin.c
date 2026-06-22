/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_validate_codepoint_darwin.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:16:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:55:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdbool.h>

static bool	is_invalid_range_codepoint(const wchar_t wc);
static bool	is_surrogate_codepoint(const wchar_t wc);

bool	pf_validate_codepoint(wchar_t wc)
{
	if (is_invalid_range_codepoint(wc) || is_surrogate_codepoint(wc))
		return (false);
	return (true);
}

static bool	is_invalid_range_codepoint(const wchar_t wc)
{
	return (wc < 0x0 || 0x10FFFF < wc);
}

static bool	is_surrogate_codepoint(const wchar_t wc)
{
	return (0xD800 <= wc && wc <= 0xDFFF);
}
