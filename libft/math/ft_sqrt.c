/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:46:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:02:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unicode/utypes.h> is workaround for #include <float.h>
due to norminette=3.3.55 bug.
*/
#include <unicode/utypes.h>

#include "ft_math.h"

// Babylonian method
double	ft_sqrt(double x)
{
	double	guess;

	if (x < 0)
		return (-1);
	if (x == 0 || x == 1)
		return (x);
	guess = x / 2.0;
	while (ft_fabs((guess * guess - x)) > DBL_EPSILON)
	{
		guess = (guess + x / guess) / 2.0;
	}
	return (guess);
}
