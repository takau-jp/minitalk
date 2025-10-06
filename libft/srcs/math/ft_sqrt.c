/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:46:06 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/24 13:55:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
